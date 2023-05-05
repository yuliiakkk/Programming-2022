
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class vehicle
{
protected:
    string name_;
    int engine_capacity;
public:
    vehicle() :
        engine_capacity(0),
        name_("")
    {
    }
    vehicle(int engine_capacity, string name_) :
    engine_capacity(engine_capacity),
    name_(name_)
    {
    }

    virtual void print() const = 0;
    string GetName() const
    {
        return name_;
    }
    int GetCapacity() const
    {
        return engine_capacity;
    }
};

class WaterVehicle: virtual public vehicle
{
private:
    int max_speed;
    string water_type;
public:
    WaterVehicle(int max_speed, string water_type) :
        max_speed(max_speed),
        water_type(water_type)
    {
    }

    string GetType() const
    {
        return water_type;
    }
    int GetMaxSpeed() const
    {
        return max_speed;
    }

    void print() const override
    {
        cout << "Water vehicle: " << GetName() << ", engine capacity: " << GetCapacity()
            << ", water type: " << GetType() << ", max speed: " << GetMaxSpeed() << endl;
    }
};

class LandVehicle :virtual public vehicle
{
private:
    int max_speed;
    int people_number;
public:
    LandVehicle(int max_speed, int people_number):
        max_speed(max_speed),
        people_number(people_number)
    {
    }
    int GetMaxSpeed() const
    {
        return max_speed;
    }
    int GetPeopleNumber() const
    {
        return people_number;
    }   

    void print() const override
    {
        cout << "Land vehicle: " << GetName() << ", engine capacity: " << GetCapacity()
            << ", max speed: " << GetMaxSpeed() << ", number of seats: " << GetPeopleNumber() << endl;
    }
};

class AmphibiaVehicle :public WaterVehicle, LandVehicle
{
private:
    int max_landhours;
    int max_waterhours;
public:
    AmphibiaVehicle(int volume, string name, string water_type, int max_speed, int maxSpeedOnLand, int numSeats, int maxHoursInWater, int maxHoursOnLand) : 
        vehicle(volume, name),
        WaterVehicle(max_speed, water_type), 
        LandVehicle(maxSpeedOnLand, numSeats),
        max_landhours(maxHoursInWater),
        max_waterhours(maxHoursOnLand)
    {
    }

    int getMaxHoursInWater() const 
    { 
        return max_waterhours; 
    }
    int getMaxHoursOnLand() const
    { 
        return max_landhours;
    }

    void print() const override
    {
        cout << "Amphibia vehicle: " << GetName() << ", engine capacity: " << GetCapacity()
            << ", water type: " << GetType() << ", max speed on water: " <<WaterVehicle:: GetMaxSpeed()
            << ", max speed on land: " << LandVehicle::GetMaxSpeed() << ", number of seats: "
            << LandVehicle::GetPeopleNumber() << ", max hours in water: " << getMaxHoursInWater()
            << ", max hours on land: " << getMaxHoursOnLand() << endl;
    }


};

int main()
{

    vector<vehicle*>fleet;
    fleet.push_back(new WaterVehicle(60, "Freshwater"));
    fleet.push_back(new LandVehicle(120, 4));
    fleet.push_back(new AmphibiaVehicle(200, "Amphibia1", "Brackishwater", 40, 80, 8, 6, 12));

    for (const auto& v : fleet)
    {
        v->print();
    }

    // Cleanup
    for (auto& v : fleet)
    {
        delete v;
    }

    return 0;
}

