#ifndef VRDATA_H
#define VRDATA_H

#include <QString>
#include <QObject>
#include "vrutilities.h"


class VRData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int gear READ getGear WRITE setGear NOTIFY gearChanged)
    Q_PROPERTY(float velocity READ getVelocity WRITE setVelocity NOTIFY velocityChanged)
    Q_PROPERTY(int rpm READ getRpm WRITE setRpm NOTIFY rpmChanged)
    Q_PROPERTY(int maxRpm READ getMaxRpm WRITE setMaxRpm NOTIFY maxRpmChanged)

    Q_PROPERTY(float throttle READ getThrottle WRITE setThrottle NOTIFY throttleChanged)
    Q_PROPERTY(float brake READ getBrake WRITE setBrake NOTIFY brakeChanged)
    Q_PROPERTY(float clutch READ getClutch WRITE setClutch NOTIFY clutchChanged)

    Q_PROPERTY(int completedLaps READ getCompletedLaps WRITE setCompletedLaps NOTIFY completedLapsChanged)

    Q_PROPERTY(float fuel READ getFuel WRITE setFuel NOTIFY fuelChanged)
    Q_PROPERTY(float maxFuel READ getMaxFuel WRITE setMaxFuel NOTIFY maxFuelChanged)

    Q_PROPERTY(bool pitLimiter READ getPitLimiter WRITE setPitLimiter NOTIFY pitLimiterChanged)
    Q_PROPERTY(bool isInPitlane READ getIsInPitlane WRITE setIsInPitlane NOTIFY isInPitlaneChanged)

    Q_PROPERTY(float brakeBias READ getBrakeBias WRITE setBrakeBias NOTIFY brakeBiasChanged)

    Q_PROPERTY(float currentLapTime READ getCurrentLapTime WRITE setCurrentLapTime NOTIFY currentLapTimeChanged)
    Q_PROPERTY(float bestLapTime READ getBestLapTime WRITE setBestLapTime NOTIFY bestLapTimeChanged)
    Q_PROPERTY(float previousLapTime READ getPreviousLapTime WRITE setPreviousLapTime NOTIFY previousLapTimeChanged)

    Q_PROPERTY(float tireWearFL READ getTireWearFL WRITE setTireWearFL NOTIFY tireWearFLChanged)
    Q_PROPERTY(float tireWearFR READ getTireWearFR WRITE setTireWearFR NOTIFY tireWearFRChanged)
    Q_PROPERTY(float tireWearRR READ getTireWearRR WRITE setTireWearRR NOTIFY tireWearRRChanged)
    Q_PROPERTY(float tireWearRL READ getTireWearRL WRITE setTireWearRL NOTIFY tireWearRLChanged)

    Q_PROPERTY(float tireTemperatureFLI READ getTireTemperatureFLI WRITE setTireTemperatureFLI NOTIFY tireTemperatureFLIChanged)
    Q_PROPERTY(float tireTemperatureFLC READ getTireTemperatureFLC WRITE setTireTemperatureFLC NOTIFY tireTemperatureFLCChanged)
    Q_PROPERTY(float tireTemperatureFLO READ getTireTemperatureFLO WRITE setTireTemperatureFLO NOTIFY tireTemperatureFLOChanged)

    Q_PROPERTY(float tireTemperatureFRI READ getTireTemperatureFRI WRITE setTireTemperatureFRI NOTIFY tireTemperatureFRIChanged)
    Q_PROPERTY(float tireTemperatureFRC READ getTireTemperatureFRC WRITE setTireTemperatureFRC NOTIFY tireTemperatureFRCChanged)
    Q_PROPERTY(float tireTemperatureFRO READ getTireTemperatureFRO WRITE setTireTemperatureFRO NOTIFY tireTemperatureFROChanged)

    Q_PROPERTY(float tireTemperatureRRI READ getTireTemperatureRRI WRITE setTireTemperatureRRI NOTIFY tireTemperatureRRIChanged)
    Q_PROPERTY(float tireTemperatureRRC READ getTireTemperatureRRC WRITE setTireTemperatureRRC NOTIFY tireTemperatureRRCChanged)
    Q_PROPERTY(float tireTemperatureRRO READ getTireTemperatureRRO WRITE setTireTemperatureRRO NOTIFY tireTemperatureRROChanged)

    Q_PROPERTY(float tireTemperatureRLI READ getTireTemperatureRLI WRITE setTireTemperatureRLI NOTIFY tireTemperatureRLIChanged)
    Q_PROPERTY(float tireTemperatureRLC READ getTireTemperatureRLC WRITE setTireTemperatureRLC NOTIFY tireTemperatureRLCChanged)
    Q_PROPERTY(float tireTemperatureRLO READ getTireTemperatureRLO WRITE setTireTemperatureRLO NOTIFY tireTemperatureRLOChanged)

    Q_PROPERTY(float brakeTemperatureFL READ getBrakeTemperatureFL WRITE setBrakeTemperatureFL NOTIFY brakeTemperatureFLChanged)
    Q_PROPERTY(float brakeTemperatureFR READ getBrakeTemperatureFR WRITE setBrakeTemperatureFR NOTIFY brakeTemperatureFRChanged)
    Q_PROPERTY(float brakeTemperatureRR READ getBrakeTemperatureRR WRITE setBrakeTemperatureRR NOTIFY brakeTemperatureRRChanged)
    Q_PROPERTY(float brakeTemperatureRL READ getBrakeTemperatureRL WRITE setBrakeTemperatureRL NOTIFY brakeTemperatureRLChanged)

    Q_PROPERTY(float tirePressureFL READ getTirePressureFL WRITE setTirePressureFL NOTIFY tirePressureFLChanged)
    Q_PROPERTY(float tirePressureFR READ getTirePressureFR WRITE setTirePressureFR NOTIFY tirePressureFRChanged)
    Q_PROPERTY(float tirePressureRR READ getTirePressureRR WRITE setTirePressureRR NOTIFY tirePressureRRChanged)
    Q_PROPERTY(float tirePressureRL READ getTirePressureRL WRITE setTirePressureRL NOTIFY tirePressureRLChanged)

    Q_PROPERTY(float tireDirtFL READ getTireDirtFL WRITE setTireDirtFL NOTIFY tireDirtFLChanged)
    Q_PROPERTY(float tireDirtFR READ getTireDirtFR WRITE setTireDirtFR NOTIFY tireDirtFRChanged)
    Q_PROPERTY(float tireDirtRR READ getTireDirtRR WRITE setTireDirtRR NOTIFY tireDirtRRChanged)
    Q_PROPERTY(float tireDirtRL READ getTireDirtRL WRITE setTireDirtRL NOTIFY tireDirtRLChanged)

    Q_PROPERTY(float currentS1 READ getCurrentS1 WRITE setCurrentS1 NOTIFY currentS1Changed)
    Q_PROPERTY(float currentS2 READ getCurrentS2 WRITE setCurrentS2 NOTIFY currentS2Changed)
    Q_PROPERTY(float currentS3 READ getCurrentS3 WRITE setCurrentS3 NOTIFY currentS3Changed)

    Q_PROPERTY(float bestS1 READ getBestS1 WRITE setBestS1 NOTIFY bestS1Changed)
    Q_PROPERTY(float bestS2 READ getBestS2 WRITE setBestS2 NOTIFY bestS2Changed)
    Q_PROPERTY(float bestS3 READ getBestS3 WRITE setBestS3 NOTIFY bestS3Changed)

    Q_PROPERTY(float previousS1 READ getPreviousS1 WRITE setPreviousS1 NOTIFY previousS1Changed)
    Q_PROPERTY(float previousS2 READ getPreviousS2 WRITE setPreviousS2 NOTIFY previousS2Changed)
    Q_PROPERTY(float previousS3 READ getPreviousS3 WRITE setPreviousS3 NOTIFY previousS3Changed)

    Q_PROPERTY(float tBestS1 READ getTBestS1 WRITE setTBestS1 NOTIFY tBestSChanged)
    Q_PROPERTY(float tBestS2 READ getTBestS2 WRITE setTBestS2 NOTIFY tBestSChanged)
    Q_PROPERTY(float tBestS3 READ getTBestS3 WRITE setTBestS3 NOTIFY tBestSChanged)

    Q_PROPERTY(float tireGripFL READ getTireGripFL WRITE setTireGripFL NOTIFY tireGripFLChanged)
    Q_PROPERTY(float tireGripFR READ getTireGripFR WRITE setTireGripFR NOTIFY tireGripFRChanged)
    Q_PROPERTY(float tireGripRR READ getTireGripRR WRITE setTireGripRR NOTIFY tireGripRRChanged)
    Q_PROPERTY(float tireGripRL READ getTireGripRL WRITE setTireGripRL NOTIFY tireGripRLChanged)

    Q_PROPERTY(float lapDistance READ getLapDistance WRITE setLapDistance NOTIFY lapDistanceChanged)

    Q_PROPERTY(long clutchDisengagedTime READ getClutchDisengagedTime WRITE setClutchDisengagedTime NOTIFY clutchDisengagedTimeChanged)
    Q_PROPERTY(long gearChangeTime READ getGearChangeTime WRITE setGearChangeTime NOTIFY gearChangeTimeChanged)

public:
    VRData();

    Q_INVOKABLE double getTimeInSeconds();

    int getGear() const;
    void setGear(int value);

    float getVelocity() const;
    void setVelocity(float value);

    int getRpm() const;
    void setRpm(int value);

    int getMaxRpm() const;
    void setMaxRpm(int value);

    float getThrottle() const;
    void setThrottle(float value);

    float getBrake() const;
    void setBrake(float value);

    float getClutch() const;
    void setClutch(float value);

    int getCompletedLaps() const;
    void setCompletedLaps(int value);

    float getFuel() const;
    void setFuel(float value);

    float getMaxFuel() const;
    void setMaxFuel(float value);

    bool getPitLimiter() const;
    void setPitLimiter(bool value);

    bool getIsInPitlane() const;
    void setIsInPitlane(bool value);

    float getBrakeBias() const;
    void setBrakeBias(float value);

    float getCurrentLapTime() const;
    void setCurrentLapTime(float value);

    float getBestLapTime() const;
    void setBestLapTime(float value);

    float getPreviousLapTime() const;
    void setPreviousLapTime(float value);

    float getTireWearFL() const;
    void setTireWearFL(float value);

    float getTireWearFR() const;
    void setTireWearFR(float value);

    float getTireWearRR() const;
    void setTireWearRR(float value);

    float getTireWearRL() const;
    void setTireWearRL(float value);

    float getTireTemperatureFLI() const;
    void setTireTemperatureFLI(float value);

    float getTireTemperatureFLC() const;
    void setTireTemperatureFLC(float value);

    float getTireTemperatureFLO() const;
    void setTireTemperatureFLO(float value);

    float getTireTemperatureFRI() const;
    void setTireTemperatureFRI(float value);

    float getTireTemperatureFRC() const;
    void setTireTemperatureFRC(float value);

    float getTireTemperatureFRO() const;
    void setTireTemperatureFRO(float value);

    float getTireTemperatureRRI() const;
    void setTireTemperatureRRI(float value);

    float getTireTemperatureRRC() const;
    void setTireTemperatureRRC(float value);

    float getTireTemperatureRRO() const;
    void setTireTemperatureRRO(float value);

    float getTireTemperatureRLI() const;
    void setTireTemperatureRLI(float value);

    float getTireTemperatureRLC() const;
    void setTireTemperatureRLC(float value);

    float getTireTemperatureRLO() const;
    void setTireTemperatureRLO(float value);

    float getBrakeTemperatureFL() const;
    void setBrakeTemperatureFL(float value);

    float getBrakeTemperatureFR() const;
    void setBrakeTemperatureFR(float value);

    float getBrakeTemperatureRR() const;
    void setBrakeTemperatureRR(float value);

    float getBrakeTemperatureRL() const;
    void setBrakeTemperatureRL(float value);

    float getTirePressureFL() const;
    void setTirePressureFL(float value);

    float getTirePressureFR() const;
    void setTirePressureFR(float value);

    float getTirePressureRR() const;
    void setTirePressureRR(float value);

    float getTirePressureRL() const;
    void setTirePressureRL(float value);

    float getTireDirtFL() const;
    void setTireDirtFL(float value);

    float getTireDirtFR() const;
    void setTireDirtFR(float value);

    float getTireDirtRR() const;
    void setTireDirtRR(float value);

    float getTireDirtRL() const;
    void setTireDirtRL(float value);

    float getCurrentS1() const;
    void setCurrentS1(float value);

    float getCurrentS2() const;
    void setCurrentS2(float value);

    float getCurrentS3() const;
    void setCurrentS3(float value);

    float getBestS1() const;
    void setBestS1(float value);

    float getBestS2() const;
    void setBestS2(float value);

    float getBestS3() const;
    void setBestS3(float value);

    float getPreviousS1() const;
    void setPreviousS1(float value);

    float getPreviousS2() const;
    void setPreviousS2(float value);

    float getPreviousS3() const;
    void setPreviousS3(float value);

    float getTBestS1() const;
    void setTBestS1(float value);

    float getTBestS2() const;
    void setTBestS2(float value);

    float getTBestS3() const;
    void setTBestS3(float value);

    float getTireGripFL() const;
    void setTireGripFL(float value);

    float getTireGripFR() const;
    void setTireGripFR(float value);

    float getTireGripRR() const;
    void setTireGripRR(float value);

    float getTireGripRL() const;
    void setTireGripRL(float value);

    float getLapDistance() const;
    void setLapDistance(float value);

    long getClutchDisengagedTime() const;
    void setClutchDisengagedTime(long value);

    long getGearChangeTime() const;
    void setGearChangeTime(long value);

signals:
    void gearChanged();
    void velocityChanged();
    void rpmChanged();
    void maxRpmChanged();

    void throttleChanged();
    void brakeChanged();
    void clutchChanged();

    void completedLapsChanged();

    void fuelChanged();
    void maxFuelChanged();

    void pitLimiterChanged();
    void isInPitlaneChanged();

    void brakeBiasChanged();

    void currentLapTimeChanged();
    void bestLapTimeChanged();
    void previousLapTimeChanged();

    void tireWearFLChanged();
    void tireWearFRChanged();
    void tireWearRRChanged();
    void tireWearRLChanged();

    void tireTemperatureFLIChanged();
    void tireTemperatureFLCChanged();
    void tireTemperatureFLOChanged();

    void tireTemperatureFRIChanged();
    void tireTemperatureFRCChanged();
    void tireTemperatureFROChanged();

    void tireTemperatureRRIChanged();
    void tireTemperatureRRCChanged();
    void tireTemperatureRROChanged();

    void tireTemperatureRLIChanged();
    void tireTemperatureRLCChanged();
    void tireTemperatureRLOChanged();

    void brakeTemperatureFLChanged();
    void brakeTemperatureFRChanged();
    void brakeTemperatureRRChanged();
    void brakeTemperatureRLChanged();

    void tirePressureFLChanged();
    void tirePressureFRChanged();
    void tirePressureRRChanged();
    void tirePressureRLChanged();

    void tireDirtFLChanged();
    void tireDirtFRChanged();
    void tireDirtRRChanged();
    void tireDirtRLChanged();

    void currentS1Changed();
    void currentS2Changed();
    void currentS3Changed();

    void bestS1Changed();
    void bestS2Changed();
    void bestS3Changed();

    void previousS1Changed();
    void previousS2Changed();
    void previousS3Changed();

    void tBestSChanged();

    void tireGripFLChanged();
    void tireGripFRChanged();
    void tireGripRRChanged();
    void tireGripRLChanged();

    void lapDistanceChanged();

    void clutchDisengagedTimeChanged();
    void gearChangeTimeChanged();

private:
    //
    // Application information
    //
    std::chrono::milliseconds startTime;

    //
    // Session information
    //

    //QString playerName;
    /* TODO:
    Getting the car name is a bit difficult for RRRE,
    I know that there is a huge JSON containing all the cars
    with their corresponding IDs somewhere. The simulation
    itself only gives us the IDs.
    */
    //QString carName;
    //QString trackName;

    int completedLaps;

    //
    // Car information
    //

    // -1 = reverse (R), 0 = neutral (N)
    int gear;

    // in km/h
    float velocity;

    int rpm;
    int maxRpm;

    // Pedal positions
    // from 0 to 1
    float throttle;
    float brake;
    float clutch;

    // Tire Info
    // Tire Pressures in Bar
    float tirePressureFL;
    float tirePressureFR;
    float tirePressureRR;
    float tirePressureRL;

    float tireWearFL;
    float tireWearFR;
    float tireWearRR;
    float tireWearRL;

    // Tire dirt in %
    float tireDirtFL;
    float tireDirtFR;
    float tireDirtRR;
    float tireDirtRL;

    // Tire temperatures of three points across the tread of the tire (in Celcius)
    float tireTemperatureFLI;
    float tireTemperatureFLC;
    float tireTemperatureFLO;

    float tireTemperatureFRI;
    float tireTemperatureFRC;
    float tireTemperatureFRO;

    float tireTemperatureRRI;
    float tireTemperatureRRC;
    float tireTemperatureRRO;

    float tireTemperatureRLI;
    float tireTemperatureRLC;
    float tireTemperatureRLO;

    // in Celcius
    float brakeTemperatureFL;
    float brakeTemperatureFR;
    float brakeTemperatureRR;
    float brakeTemperatureRL;

    // Damage
    // TODO: AC and R3E work a bit different here, not sure what's the best way to handle this.

    // in l
    float fuel;
    float maxFuel;

    // How much the brakes are biased towards the front
    float brakeBias;

    // false = inactive, true = active
    bool pitLimiter;

    // true = in pitlane
    bool isInPitlane;

    // true = in pit
    //bool isInPit;

    //
    // Timing information
    //

    // in s
    float currentLapTime;
    float bestLapTime;
    float previousLapTime;

    float currentS1;
    float currentS2;
    float currentS3;

    float bestS1;
    float bestS2;
    float bestS3;

    float previousS1;
    float previousS2;
    float previousS3;

    float tBestS1;
    float tBestS2;
    float tBestS3;

    //int currentSector;
    //float currentLapSectorTimes[3];
    //float bestLapSectorTimes[3];
    //float previousLapSectorTimes[3];
    //float bestSectorTimes[3];

    //
    // Values used mainly for analytics for now.
    //

    // Tire grip values
    float tireGripFL;
    float tireGripFR;
    float tireGripRR;
    float tireGripRL;

    // Lap distance information
    float lapDistance;

    // Shift time info for analytics
    long clutchDisengagedTime;
    long gearChangeTime;

    /* TODO:
    Things that might be added later:
        - Session type
        - Flag information
        - DRS and P2P information
        - Engine fluid temperatures etc.
        - Race info (I hope AC provides enough info, not sure atm.)
        - ...
    */
};

#endif //VRDATA_H
