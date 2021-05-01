#!/bin/bash

# https://ros-planning.github.io/moveit_tutorials/doc/getting_started/getting_started.html

# Install Catkin
rosdep update
sudo apt update
sudo apt dist-upgrade

# Install catkin the ROS build system and wstool
sudo apt install ros-noetic-catkin python3-catkin-tools
sudo apt install python3-wstool

# Create A Catkin Workspace and Download MoveIt Source
mkdir -p ~/ws_moveit/src
cd ~/ws_moveit/src

wstool init .
wstool merge -t . https://raw.githubusercontent.com/ros-planning/moveit/master/moveit.rosinstall
wstool remove  moveit_tutorials  # this is cloned in the next section
wstool update -t .

# Download Example Code
cd ~/ws_moveit/src
git clone https://github.com/ros-planning/moveit_tutorials.git -b master
git clone https://github.com/ros-planning/panda_moveit_config.git -b melodic-devel

# Build your Catkin Workspace
cd ~/ws_moveit/src
rosdep install -y --from-paths . --ignore-src --rosdistro noetic

sudo sh -c 'echo "deb http://packages.ros.org/ros-testing/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt update

cd ~/ws_moveit
catkin config --extend /opt/ros/${ROS_DISTRO} --cmake-args -DCMAKE_BUILD_TYPE=Release
catkin build

# Source the catkin workspace:
source ~/ws_moveit/devel/setup.bash
echo 'source ~/ws_moveit/devel/setup.bash' >> ~/.bashrc