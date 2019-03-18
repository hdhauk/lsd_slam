/**
* This file is part of LSD-SLAM.
*
* Copyright 2013 Jakob Engel <engelj at in dot tum dot de> (Technical University of Munich)
* For more information see <http://vision.in.tum.de/lsdslam> 
*
* LSD-SLAM is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* LSD-SLAM is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with LSD-SLAM. If not, see <http://www.gnu.org/licenses/>.
*/

#include "LiveSLAMWrapper.h"

#include <boost/thread.hpp>
#include "util/settings.h"
#include "util/globalFuncs.h"
#include "SlamSystem.h"


#include "IOWrapper/ROS/ROSImageStreamThread.h"
#include "IOWrapper/ROS/ROSOutput3DWrapper.h"
#include "IOWrapper/ROS/rosReconfigure.h"

#include <ros/package.h>
#include <ros/ros.h>
#include <X11/Xlib.h>
#include <getopt.h>

using namespace lsd_slam;
int main( int argc, char** argv )
{
    XInitThreads();

	ros::init(argc, argv, "LSD_SLAM");

	dynamic_reconfigure::Server<lsd_slam::LSDParamsConfig> srv(ros::NodeHandle("~"));
	srv.setCallback(dynConfCb);

	dynamic_reconfigure::Server<lsd_slam::LSDDebugParamsConfig> srvDebug(ros::NodeHandle("~Debug"));
	srvDebug.setCallback(dynConfCbDebug);

	constexpr int noArg = 0;
	constexpr int required = 1;
	constexpr int optional = 2;
	const struct option longopts[] =
		{
			{"input", required, nullptr, 'i'},
			{"config", required, nullptr, 'c'},
		};

	int opt;
	int idx;
	std::string input_channel = "/camera/image_raw";
	std::string config_file;
	while ((opt = getopt_long(argc, argv, "i:c:", longopts, &idx)) != -1)
	{
		switch(opt)
		{
			case 'i':
				input_channel = optarg;
				break;
			case 'c':
				config_file = optarg;
				break;
			default:
				printf("unknown command line option\n");
				return 1;
		}
	}


	InputImageStream* inputStream = new ROSImageStreamThread(input_channel);
	inputStream->setCalibration(config_file);
	inputStream->run();

	Output3DWrapper* outputWrapper = new ROSOutput3DWrapper(inputStream->width(), inputStream->height());
	LiveSLAMWrapper slamNode(inputStream, outputWrapper);
	slamNode.Loop();



	if (inputStream != nullptr)
		delete inputStream;
	if (outputWrapper != nullptr)
		delete outputWrapper;

	return 0;
}
