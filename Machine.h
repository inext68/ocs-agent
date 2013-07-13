/*
 * Machine.h
 *
 *  Created on: 11/lug/2013
 *      Author: stefano
 */

#ifndef MACHINE_H_
#define MACHINE_H_

#include <map>
#include <string>


class Machine {
public:
	Machine();
	~Machine();

	void RetrieveData();

	std::string BIOSManufacturer() const;
	std::string BIOSDate() const;
	std::string BIOSVersion() const;
	std::string SystemModel() const;
	std::string MachineManufacturer() const;
	std::string SystemSerialNumber() const;

	int CountProcessors() const;
	std::string ProcessorInfo(const char* info, int num) const;

private:
	void _GetDMIDecodeData();
	void _GetCPUInfo();
	void _GetSystemInfo(std::istream& stream, std::string header);

	std::string _GetValue(std::string string, std::string header) const;

	// TODO: Use a std::vector, more than 16 cpu aren't uncommon nowadays
	int fNumCPUs;
	std::map<std::string, std::string> fCPUInfo[16];
	std::map<std::string, std::string> fSystemInfo;
};

#endif /* MACHINE_H_ */
