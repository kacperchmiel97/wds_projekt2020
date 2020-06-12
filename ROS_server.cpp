#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>
#include <iostream>
#include <arpa/inet.h>
#include "ros/ros.h"
#include "std_msgs/Float32.h"

#define PORT 4242

using namespace std;

std_msgs::Float32 tilt, pid;
int conn_socket;

int connect(void);

void pidCallback(const std_msgs::Float32::ConstPtr& msg){
    pid= *msg;
}

void tiltCallback(const std_msgs::Float32::ConstPtr& msg){
    tilt= *msg;
}

void timerCallback(const ros::TimerEvent&){
    string buffer;
    
    buffer.clear();
    buffer.append(to_string(tilt.data)).append(" "); //tilt
    buffer.append("0 "); //x
    buffer.append("0 "); //y
    buffer.append("0 "); //t
    buffer.append(to_string(pid.data)).append("\n"); //pid

    send(conn_socket, buffer.c_str() , buffer.size() , 0 );
    cout << buffer << '\n';
}

int main(int argc, char *argv[]) 
{ 
    string buffer;
    
    ros::init(argc, argv, "monitor_bridge");
    ros::NodeHandle h;

    ros::Subscriber pid_sub= h.subscribe("teleop/pid/tilt/output", 100, pidCallback);
    ros::Subscriber tilt_sub= h.subscribe("teleop/angle", 100, tiltCallback);
    ros::Timer timer = h.createTimer(ros::Duration(0.05), timerCallback);
    
    conn_socket= connect();
    
    // ros::spin();
    while(true)
	ros::spinOnce();
    
    return 0; 
} 

int connect(void){
    int server_fd, new_socket; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
	perror("socket failed"); 
	exit(EXIT_FAILURE); 
    } 
	
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
	perror("setsockopt"); 
	exit(EXIT_FAILURE); 
    }
    
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr("192.168.1.163");
    address.sin_port = htons(PORT); 
	
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address, 
	     sizeof(address))<0) 
    { 
	perror("bind failed"); 
	exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
	perror("listen"); 
	exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
			     (socklen_t*)&addrlen))<0) 
    { 
	perror("accept"); 
	exit(EXIT_FAILURE); 
    }

    return new_socket;
}
