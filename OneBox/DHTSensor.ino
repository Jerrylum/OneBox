void DHTSetup() {
  // Initialize device.
  sensor_t sensor;
  dht.begin();
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

int getTemp()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  return (event.temperature);
}

int getHumidity()
{
  sensors_event_t event;
  dht.humidity().getEvent(&event);
  return (event.relative_humidity);
}
