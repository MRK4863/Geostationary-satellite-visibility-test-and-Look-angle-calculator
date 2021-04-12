# Requirements
## Introduction
* Geostationary satellites are only placed along the equator, in a circular orbit at an altitude of 35786 Kms from the earth's surface. The importance of Geostationary satellites lie in the communication applications, as the time period of revolution of satellite is equal to the rotation of earth on its axis in 24 hour time period, making them apt for communcation applications.
* This program provides us an application oriented software, that helps identify the look angles at which an antenna at the earth station should be oriented to in order for best signal reception from the satellite

## Research
### Look Angles

The following two angles of earth station antenna combined together are called as look angles.

 *   Azimuth Angle
 *   Elevation Angle

Generally, the values of these angles change for non-geostationary orbits. Whereas, the values of these angles don’t change for geostationary orbits. Because, the satellites present in geostationary orbits appear stationary with respect to earth.

These two angles are helpful in order to point at the satellite directly from the earth station antenna. So, the maximum gain of the earth station antenna can be directed at satellite.

We can calculate the look angles of geostationary orbit by using longitude & latitude of earth station and position of satellite orbit.
Azimuth Angle

The angle between local horizontal plane and the plane passing through earth station, satellite and center of earth is called as azimuth angle.

The formula for Azimuth angle (α) is


![Description](https://github.com/MRK4863/LTTS_project/blob/main/1_Requirements/azimuth_formula.jpg)

Where,

*    L is Latitude of earth station antenna.

*    G is the difference between position of satellite orbit and earth station antenna.
![Description](https://github.com/MRK4863/LTTS_project/blob/main/1_Requirements/azimuth_angle.png)

Measure the horizontal angle at earth station antenna to north pole as shown in figure. It represents azimuth angle. It is used to track the satellite horizontally.
### Elevation Angle

The angle between vertical plane and line pointing to satellite is known as Elevation angle. Vertical plane is nothing but the plane, which is perpendicular to horizontal plane.

The formula for Elevation angle (β) is

![Description](https://github.com/MRK4863/LTTS_project/blob/main/1_Requirements/elevation_formula.jpg)

We can calculate the elevation angle by using above formula. The following figure illustrates the elevation angle.

The following figure illustrates the azimuth angle.

![Description](https://github.com/MRK4863/LTTS_project/blob/main/1_Requirements/elevation_angle.png)

## Cost and Features with Time 
| Time | Feature | Cost  |
| -----| ------  | ----- |
| 1    |Azimuth  | O(1)  |
| 1    |Elevation| O(1)  |

## Defining Our System

### Explanation:
* Geostationary satellite management system and Look-angle calculator Application have few inbuilt features like:
    * Read existing Geostationary satellite Database
    * Modify and add data to the Geostationary satellite Database 
    * Calculate the look-angles for the antenna placed at an Earth-station

## SWOT ANALYSIS
![SWOT Analysis](https://github.com/MRK4863/LTTS_project/blob/main/1_Requirements/swot_analysis.png)

# 4W&#39;s and 1&#39;H

## Who:
* Tele-medicine, Research, Communication, Defense industries etc.

## What:
* Many customers can directly use the software to optimize their antennas and provide best services

## When:
* This is usually done by government bodies, but the services can be outsourced to private agencies.

## Where:
* This problem is being faced world-wide by New and emerging technology companies and indiustries.

## How:
* This problem will require an authorized and qualified personnel to evaluate various dependent parameters. This software eliminates such dependecies.

# Detail requirements
## High Level Requirements: 
| ID | Description | Category | Status | 
| ----- | ----- | ------- | ---------|
| HR01 | User shall be able to read the co-ordinates of existing satellite | Techincal | TBD-S1 | 
| HR02 | User shall be able to input the earth station location | Techincal | TBD-S1 |
| HR03 | User shall be able to evaluate the antennae look angles | Techincal | TBD-S1 |
| HR04 | User shall be able to modify existing satellite datebase | FUTURE | TBD-S1 |
| HR05 | User shall be able to add a new satellite to the database | FUTURE | TBD-S1 |

