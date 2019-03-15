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

#pragma once


#include <dynamic_reconfigure/server.h>
#include "util/settings.h"



namespace lsd_slam
{


void dynConfCbDebug()
{
	freeDebugParam1 = 1.f;
	freeDebugParam2 = 1.f;
	freeDebugParam3 = 1.f;
	freeDebugParam4 = 1.f;
	freeDebugParam5 = 1.f;


	plotStereoImages = false;
	plotTrackingIterationInfo = false;
	plotTracking = false;

	printPropagationStatistics = false;
	printFillHolesStatistics = false;
	printObserveStatistics = false;
	printObservePurgeStatistics = false;
	printRegularizeStatistics = false;
	printLineStereoStatistics = false;
	printLineStereoFails = false;

	printFrameBuildDebugInfo = false;
	printMemoryDebugInfo = false;

	printTrackingIterationInfo = false;
	printThreadingInfo = false;
	printMappingTiming = false;
	printOverallTiming = false;

	printKeyframeSelectionInfo = false;
	printConstraintSearchInfo = false;
	printOptimizationInfo = false;
	printRelocalizationInfo = false;

	continuousPCOutput = false;

	saveKeyframes = false;
	saveAllTracked = false;
	saveLoopClosureImages = false;
	saveAllTrackingStages = false;
}

void dynConfCb()
{
	// Allow idepth to be (slightle) negative, to avoid introducing a bias for far-away points.
	allowNegativeIdepths = true;
	// Compute subpixel-accurate stereo disparity.
	useSubpixelStereo = true;
	// Toggle Multi-Threading of DepthMap Estimation. Disable for less CPU usage, but possibly slightly less quality.
	multiThreading = true;
	// EXPERIMENTAL: Correct for global affine intensity changes during tracking. Might help if you have Problems with Auto-Exposure.
	useAffineLightningEstimation = false;

	// Determines how often Keyframes are taken, depending on the Distance to the current Keyframe. Larger -> more Keyframes.
	// [0 <-> 20]
	KFDistWeight = 3.0f;
	// Determines how often Keyframes are taken, depending on the Overlap to the current Keyframe. Larger -> more Keyframes.
	// [0 <-> 20]
	KFUsageWeight = 4.0f;

	// Minimal Absolut Image Gradient for a Pixel to be used at all. Increase, if your camera has large image noise, Decrease if you have low image-noise and want to also exploit small gradients.
	// [1 <-> 50]
	minUseGrad = 5.0f;
	// Image intensity noise used for e.g. tracking weight calculation. Sould be set larger than the actual sensor-noise, to also account for noise originating from discretization / linear interpolation.
	// [1 <-> 50]
	cameraPixelNoise2 = 4.0f;
	// How much to smooth the depth map. Larger -> Less Smoothing
	// [0 <-> 10]
	depthSmoothingFactor = 1.f;

	// Toggle Global Mapping Component on/off. Only takes effect after a reset.
	doSlam = true;
	// Use OpenFABMAP to find large loop-closures. Only takes effect after a reset, and requires LSD-SLAM to be compiled with FabMap.
	useFabMap = false;
	// Toggle Keyframe Re-Activation on/off: If close to an existing keyframe, re-activate it instead of creating a new one.
	// If false, Map will continually grow even if the camera moves in a relatively constrained area; If false, the number of keyframes will not grow arbitrarily.
	doKFReActivation = true;
	// Toggle entire Keyframe Creating / Update module on/off:
	// If false, only the Tracking Component stays active, which will prevent rapid motion or moving objects from corrupting the map.
	doMapping = true;

	// "Maximal of Loop-Closures that are tracked initially for each new keyframe."
	// [0 <-> 50]
	maxLoopClosureCandidates = 10;
	// Threshold on reciprocal loop-closure consistency check, to be added to the map. Larger -> more (possibly wrong) Loopclosures.
	// [0 <-> 100]
	loopclosureStrictness = 1.5f;
	// How good a relocalization-attempt has to be, to be accepted. Larger -> More Strict.
	// [0 <-> 1]
	relocalizationTH = 0.7f;
}

}
