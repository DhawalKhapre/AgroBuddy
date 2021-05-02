# AgroBuddy

## Inspiration

A drought is an event of prolonged shortages in the water supply, whether atmospheric (below-average precipitation), surface water or ground water. A drought can last for months or years, or may be declared after as few as 15 days. It can have a substantial impact on the ecosystem and agriculture of the affected region and harm to the local economy. Annual dry seasons in the tropics significantly increase the chances of a drought developing and subsequent bush fires. Periods of heat can significantly worsen drought conditions by hastening evaporation of water vapor. Drought is a recurring feature of the climate in most parts of the world. However, these regular droughts have become more extreme and more unpredictable due to climate change.

Furthermore, future drought mitigation efforts would be ineffective due to the lack of a scalable, versatile, and informative tool that allows farmers to preserve energy, optimize production through proper irrigation, and plan for droughts.

## What it does

It's a nimble, scalable, and informative Ag-Tech device that helps farmers save water, irrigate efficiently, and plan for droughts. Sensor modules, database, and website are the four components of the Agro-Buddy framework.

Module : We have used Soil Moisture Sensor, Temperature and Humidity Sensor, MQ135 air quality sensor, Arduino, esp8266 module. These modules, when arranged in an enclosure to capture analysis-relevant data and send it to the Agro-Buddy.

Database : Enabled by the use the greater Agro-Buddy setup to facilitated through cloud technology. Specifically, we use Firestore from Google for real-time data aggregation and analysis, which allows for scalability and reliable statistic collection.

Website : The website includes aggregate data patterns for groups of sensors, a GPS-locating device, and comprehensive drought/crop forecasting and community data sharing in the future. The site compares aggregate data to ideal soil moisture and geographical conditions based on current data. It also shows Global Drought Data on global Map. It also features the sensor's location through satellite view on the website.

## How we built it

The Google Cloud Platform and Firestore are used in the backend. The modules were built with Arduino-compatible microcontrollers and sensors, as well as some imagination, and coded in C++.
We used Soil Moisture Sensor, Air Sensor, Temperature Sensor, Humidity Sensor, and ESP8266 to push the data into the firebase cloud. The web app was built with HTML, CSS, JavaScript, Bootstrap, and Google Charts, and Amcharts APIs.
