/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <FBSimulatorControl/FBSimulator.h>

@class FBAgentLaunchConfiguration;
@class FBApplicationLaunchConfiguration;
@class FBDiagnostic;
@class FBProcessInfo;
@class FBSimulator;
@class FBSimulatorApplication;
@class FBSimulatorBridge;
@class FBTestManager;
@protocol FBTerminationHandle;
@protocol FBJSONSerializable;

/**
 A reciever of Simulator Events
 */
@protocol FBSimulatorEventSink <NSObject>

/**
 Event for the launch of a Simulator's Container Application Process.
 This is the Simulator.app's Process.

 @param applicationProcess the Process Information for the launched Application Process.
 */
- (void)containerApplicationDidLaunch:(FBProcessInfo *)applicationProcess;

/**
 Event for the launch of a Simulator's Container Application Process.
 This is the Simulator.app's Process.

 @param applicationProcess the Process Information for the terminated Application Process.
 @param expected whether the termination was expected or not.
 */
- (void)containerApplicationDidTerminate:(FBProcessInfo *)applicationProcess expected:(BOOL)expected;

/**
 Event for the Direct Launch of a Simulator Bridge.

 @param bridge the Simulator Bridge of the Simulator.
 */
- (void)bridgeDidConnect:(FBSimulatorBridge *)bridge;

/**
 Event for the termination of a Simulator Framebuffer.

 @param bridge the Simulator Bridge of the Simulator.
 @param expected whether the termination was expected or not.
 */
- (void)bridgeDidDisconnect:(FBSimulatorBridge *)bridge expected:(BOOL)expected;

/**
 Event for the launch of a Simulator's launchd_sim.

 @param launchdSimProcess the launchd_sim process
 */
- (void)simulatorDidLaunch:(FBProcessInfo *)launchdSimProcess;

/**
 Event for the termination of a Simulator's launchd_sim.

 @param launchdSimProcess the launchd_sim process
 */
- (void)simulatorDidTerminate:(FBProcessInfo *)launchdSimProcess expected:(BOOL)expected;

/**
 Event for the launch of an Agent.

 @param launchConfig the Agent Launch Configuration that was used to launch the Agentagent.
 @param agentProcess the resulting Process Info from the launch.
 @param stdOut the stdout file handle of the launched agent, may be nil.
 @param stdErr the stderr file handle of the launched agent, may be nil.
 */
- (void)agentDidLaunch:(FBAgentLaunchConfiguration *)launchConfig didStart:(FBProcessInfo *)agentProcess stdOut:(NSFileHandle *)stdOut stdErr:(NSFileHandle *)stdErr;

/**
 Event of the termination of an agent.

 @param agentProcess the process that was terminated.
 @param expected whether the termination was expected or not.
 */
- (void)agentDidTerminate:(FBProcessInfo *)agentProcess expected:(BOOL)expected;

/**
 Event for the launch of an Application.

 @param launchConfig the Application Launch Configuration that was used to launch the Application.
 @param applicationProcess the resulting Process Info from the launch.
 */
- (void)applicationDidLaunch:(FBApplicationLaunchConfiguration *)launchConfig didStart:(FBProcessInfo *)applicationProcess;

/**
 Event for the termination of an Application.

 @param applicationProcess the process that was terminated.
 @param expected whether the termination was expected or not.
 */
- (void)applicationDidTerminate:(FBProcessInfo *)applicationProcess expected:(BOOL)expected;

/**
 Event for connection of test manager daemon

 @param testManager connected test manager
 */
- (void)testmanagerDidConnect:(FBTestManager *)testManager;

/**
 Event for disconnection of test manager daemon

 @param testManager disconnected test manager
 */
- (void)testmanagerDidDisconnect:(FBTestManager *)testManager;

/**
 Event for the availablilty of a new log.

 @param diagnostic the diagnostic log.
 */
- (void)diagnosticAvailable:(FBDiagnostic *)diagnostic;

/**
 Event for the change in a Simulator's state.

 @param state the changed state.
 */
- (void)didChangeState:(FBSimulatorState)state;

/**
 Event for the availibility of new Termination Handle.

 @param terminationHandle the Termination Handle that is required to be called on Simulator teardown.
 */
- (void)terminationHandleAvailable:(id<FBTerminationHandle>)terminationHandle;

@end
