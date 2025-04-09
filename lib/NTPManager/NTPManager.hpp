#pragma once
#include <ezTime.h>
extern Timezone timeZone;

// Function to setup NTP
void setupNTP();

// Function to loop NTP
void loopNTP();

// Function to get the Timestamp to write it in the JSON
String getTimestamp();
