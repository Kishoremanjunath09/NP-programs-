#include <fstream>
#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/applications-module.h"
#include "ns3/internet-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int 
main (int argc, char *argv[])
{
  //Address serverAddress;

  NodeContainer nodes;
  nodes.Create (4);
  InternetStackHelper stack;
  stack.Install (nodes);
  CsmaHelper csma;
  csma.SetChannelAttribute ("DataRate", DataRateValue (DataRate (5000000)));
  csma.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (2)));
  csma.SetDeviceAttribute ("Mtu", UintegerValue (1400));
  //mtu->maximun transmission unit 
  NetDeviceContainer device = csma.Install (nodes);
  

  Ipv4AddressHelper address;
      address.SetBase ("10.1.1.0", "255.255.255.0");
      
  Ipv4InterfaceContainer interface = address.Assign (device);
      //serverAddress = Address(i.GetAddress (1));
   
 // uint16_t port = 9;  // well-known echo port number
  UdpEchoServerHelper echoserver (9);
  ApplicationContainer apps = echoserver.Install (nodes.Get (1));
  apps.Start (Seconds (1.0));
  apps.Stop (Seconds (10.0));


  //uint32_t packetSize = 1024;
  //uint32_t maxPacketCount = 1;
  //Time interPacketInterval = Seconds (1.);
  UdpEchoClientHelper echoclient (interface.GetAddress(1),9);
  client.SetAttribute ("MaxPackets", UintegerValue (1));
  client.SetAttribute ("Interval", TimeValue (Seconds(1.0));
  client.SetAttribute ("PacketSize", UintegerValue (1024));
  apps = echoclient.Install (nodes.Get (0));
  apps.Start (Seconds (2.0));
  apps.Stop (Seconds (10.0));

//setting payload
#if 0
echoclient.SetFill (apps.Get (0), "Hello World");
echoclient.SetFill (apps.Get (0), 0xa5, 1024);
uint8_t fill[] = { 0, 1, 2, 3, 4, 5, 6};
  echoclient.SetFill (apps.Get (0), fill, sizeof(fill), 1024);
#endif
AnimationInterface anim ("second.xml");
  Simulator::Run ();
  Simulator::Destroy ();
  
}
