#include "vrsimulationmanager.h"

VRSimulationManager::VRSimulationManager() {
    this->running = false;
    this->timerId = -1;
}

VRSimulationManager::~VRSimulationManager() {

}

bool VRSimulationManager::start() {
    waitForSim();
    if (!connectToSharedMemory()) {
        this->dataInterface.clear();
        return false;
    }

    // Start Timer with 10 ms interval
    this->timerId = startTimer(10);
    this->running = true;

    // this->dataInterface.clear();
    return true;
}

bool VRSimulationManager::isRunning() {
    return this->running;
}

QSharedPointer<VRDataInterface> VRSimulationManager::getDataInterface()
{
    return this->dataInterface;
}

void VRSimulationManager::waitForSim() {
    std::cout << "SimulationManager is waiting for a simulation to start ..." << std::endl;

    while(true) { // TODO: Timeout?
        if (VRUtilities::isProcessRunning(vrconstants::r3eProcessName)) { // TODO: Optimize duplicate call for different simulations?
            this->dataInterface = VRDataInterfaceFactory::createInterface(VRDataInterfaceFactory::Simulation::R3E);
            std::cout << " -> R3E running." << std::endl;
            return;
        } else if (VRUtilities::isProcessRunning(vrconstants::acProcessName)) {
            this->dataInterface = VRDataInterfaceFactory::createInterface(VRDataInterfaceFactory::Simulation::AC);
            std::cout << " -> AC running." << std::endl;
            return;
        }

        Sleep(vrconstants::lookForRunningSimInterval);
    }
}

bool VRSimulationManager::connectToSharedMemory() {
    std::cout << "Simulation is running, trying to connect to shared memory ..." << std::endl;

    bool success = false;
    while(VRUtilities::isProcessRunning(this->dataInterface->getProcessName())) { // TODO: TIMEOUT
        success = this->dataInterface->start();
        if (success)
            break;

        Sleep(vrconstants::connectToSharedMemoryInterval);
    }
    if (success)
        std::cout << "DataInterface started, connected to shared memory!" << std::endl;
    else
        std::cout << "Could not connect to shared memory, simulation is not running anymore." << std::endl;

    return success;
}

void VRSimulationManager::timerEvent(QTimerEvent* event)
{
    bool success = true;

    if (VRUtilities::isProcessRunning(this->dataInterface->getProcessName()))
    {
        success = this->dataInterface->update();
    }
    else
    {
        success = false;
    }

    if (!success)
    {
        std::cout << "Could not update, simulation might not be running or shared memory is not attached." << std::endl;

        // Stop timer.
        killTimer(this->timerId);
        this->running = false;
        this->dataInterface.clear();
    }
}
