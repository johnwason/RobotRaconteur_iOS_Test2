//
//  RRTest.h
//  RobotRaconteur_iOS_Test
//
//  Created by John Wason on 9/2/13.
//  Copyright (c) 2013 John Wason. All rights reserved.
//

#include <RobotRaconteur.h>
#include "com__robotraconteur__testing__TestService1.h"
#include "com__robotraconteur__testing__TestService1_stubskel.h"
#include "com__robotraconteur__testing__TestService2_stubskel.h"
#include "ServiceTestClient.h"


#include "ServiceTestClient.h"

#ifndef RobotRaconteur_iOS_Test_RRTest_h
#define RobotRaconteur_iOS_Test_RRTest_h

using namespace RobotRaconteur;
using namespace RobotRaconteurTest;
using namespace std;
using namespace com::robotraconteur::testing::TestService1;
using namespace com::robotraconteur::testing::TestService2;

void rr_init()
{
    RobotRaconteurNode::s()->SetLogLevel(RobotRaconteur_LogLevel_Debug);
    
    RR_SHARED_PTR<TcpTransport> c=RR_MAKE_SHARED<TcpTransport>();
    c->EnableNodeAnnounce(IPNodeDiscoveryFlags_NODE_LOCAL | IPNodeDiscoveryFlags_LINK_LOCAL | IPNodeDiscoveryFlags_SITE_LOCAL);
    c->EnableNodeDiscoveryListening(IPNodeDiscoveryFlags_NODE_LOCAL | IPNodeDiscoveryFlags_LINK_LOCAL | IPNodeDiscoveryFlags_SITE_LOCAL);
    
    RobotRaconteurNode::s()->RegisterTransport(c);
    RobotRaconteurNode::s()->RegisterServiceType(RR_MAKE_SHARED<com__robotraconteur__testing__TestService1Factory>());
    RobotRaconteurNode::s()->RegisterServiceType(RR_MAKE_SHARED<com__robotraconteur__testing__TestService2Factory>());
}

void rr_runtest()
{
   
    
    ServiceTestClient cl;
    cl.RunFullTest("rr+tcp://192.168.1.118:22222/?service=RobotRaconteurTestService", "rr+tcp://192.168.1.118:22222?service=RobotRaconteurTestService_auth");
    
    //RobotRaconteurNode::s()->Shutdown();
    
    
}



#endif
