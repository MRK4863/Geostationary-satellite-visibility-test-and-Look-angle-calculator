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

α=180+aTan(Tan(G)/Tan(L))

Where,

*    L is Latitude of earth station antenna.

*    G is the difference between position of satellite orbit and earth station antenna.

Measure the horizontal angle at earth station antenna to north pole as shown in figure. It represents azimuth angle. It is used to track the satellite horizontally.
### Elevation Angle

The angle between vertical plane and line pointing to satellite is known as Elevation angle. Vertical plane is nothing but the plane, which is perpendicular to horizontal plane.

The formula for Elevation angle (β) is



We can calculate the elevation angle by using above formula. The following figure illustrates the elevation angle.

The following figure illustrates the azimuth angle.

## Cost and Features with Time 
| Time | Feature | Cost |
| ----- | ----- | ----- |
| 10

## Defining Our System
### Certain assumptions:
* Few systems already exists with which our system will interact
    * Hospital Management Application
    * Analytics System
    * Emergency Services
![Description](https://github.com/arc-arnob/LnT_Mini_Project/blob/main/1_Requirements/system.png)
### Explanation:
* Patient Management Application have few inbuilt features like:
    * Create a patient record
    * Delete a patient record
    * Read a patient record
    * Update a patient record
    * Save record to file
    * Read record from file 

* Since we have assumed that few systems already exists we can say that in future sprints new features could be added in which for instance patient record from PMS can be sent to HMS or Analytics or even to emegency services if some patient record shows abnormal pattern.

## SWOT ANALYSIS
![SWOT Analysis](https://github.com/arc-arnob/LnT_Mini_Project/blob/main/1_Requirements/swot.png)

# 4W&#39;s and 1&#39;H

## Who:
* Small and medium size clinics Providing Covid vaccinations to patients

## What:
* Many Clinics are not able to afford high end HMS or ERP systems and hence still depend on manual filing systems. During COVID vaccinations it becomes a tedious task to manage every patient with hand written file system

## When:
* This problem began in February 2021, when COVID Vaccination Drive began and small/medium clinics will soon have to administer vaccinations to people.

## Where:
* This problem is expected to surface in all states of India.

## How:
* This problem may cause ineffective vaccine management and hence there can be a huge amount of vaccine wastage. As per recent data in cities like Noida and Delhi till date 9%-18% vaccines have gone to waste.

# Detail requirements
## High Level Requirements: 
| ID | Description | Category | Status | 
| ----- | ----- | ------- | ---------|
| HR01 | User shall be able to add new patient record | Techincal | TBD-S1 | 
| HR02 | User shall be able to read a patient record | Techincal | TBD-S1 |
| HR03 | User shall be able to update a patient record | Techincal | TBD-S1 |
| HR04 | User shall be able to delete a patient record | Techincal | TBD-S1 |
| HR05 | User shall be able to save records in a file | Techincal | TBD-S1 |
| HR06 | User shall be able to read data from a file | Techincal | TBD-S1 |
| HR07 | Data should not be lost in case of faliure | Scenario | FUTURE |
| HR08 | Data should always be stored when closing the system | Scenario | TBD-S1 |
##  Low level Requirements:
 
| ID | Description | HLR ID | Status (Implemented/Future) |
| ------ | --------- | ------ | ----- |
| LR01 | New record shall be added by providing all the asked information and the id should be unique or else patient record should not be accepted. | HR01 | TBD-S1 |
| LR02 | Reading patient data should be possible in 2 ways, first being by searching by id of a patient and second by printing all the records available | HR02 | TBD-S1 |
| LR03 | While reading all the records, only 10 records per page should be visible and should add 10 more if user wants to see more | HR02 | FUTURE |
| LR04 | If user searches for an invalid ID "No Record Found" message should be displayed | HR02 | TBD-S1 |
| LR05 | User need to search by id for the pateint record to be updated, if no such record is available then "No Record Found" Message should be displayed | HR03 | TBD-S1 |
| LR06 | User need to search by id for the pateint record to be deleted, if no such record is available then "No Record Found" Message should be displayed | HR04 | TBD-S1 |
| LR05 | User shall be able to save the files, if file already exists then it should append to file and should not overwrite it and if file does not exists then it should create a new file | HR05 | TBD-S1 |
| LR06 | If opening the file fails, then the system shloud prompt the message "Unable to access file" and should not end the program execution | HR05, HR06, HR07, HR08 | TBD-S1 |
| LR07 | When user Log off the system, message shall be prompted asking the user to save new records to file before exiting or not | HR08 | TBD-S1 |