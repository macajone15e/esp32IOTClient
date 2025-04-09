#pragma once
#include <Arduino.h>


// Function to generate JSON string
// Parameters:
//   - id: Client ID
//   - timestamp: Timestamp string
//   - temperature: Temperature value
//   - altitude: Altitude value
//   - pressure: Pressure value
// Returns: JSON string
String generateJson(String id, String timestamp, float temperature, float altitude, float pressure);
