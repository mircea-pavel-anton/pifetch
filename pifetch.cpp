#include <iostream>
#include <string.h>

using std::string;
using std::cout;
using std::endl;

namespace Colors {  
    namespace Bold {
        static const char *Red 	 = "\033[1;31m";
        static const char *Green = "\033[1;32m";
    }
    
    static const char *Reset = "\033[0m";
}

string run_command(string _cmd) {
	const int MAX_BUFF = 256;
	string mData;
	FILE *mStream;
	char mBuff[MAX_BUFF];
	_cmd.append(" 2>&1");

	mStream = popen(_cmd.c_str(), "r");
	if (mStream) {
		while (!feof(mStream))
		if (fgets(mBuff, MAX_BUFF, mStream) != NULL) 
			mData.append(mBuff);
		pclose(mStream);
	} else {
		std::cout << "Failed to run command." << std::endl;
		exit(1);
	}
	if (mData[(mData.size()) - 1] == '\n') mData.pop_back();
	return mData;
}

int main(void) {
    string mUsername = run_command("whoami");
    string mHostname = run_command("hostname");
    string mDevice = run_command("lshw 2> /dev/null| grep product | head -n 1").substr(13);
    string mOS = run_command("cat /etc/*-release | grep PRETTY_NAME").substr(13); mOS.pop_back();
    string mKernel = run_command("uname -r");
    string mBits = run_command("lshw 2> /dev/null| grep width | head -n 1").substr(11);
    string mUptime = run_command("uptime -p").substr(3);
    int mPackages = std::stoi(run_command("apt list --installed 2>/dev/null | wc -l")) - 1;
    int mContainers = std::stoi(run_command("docker ps | wc -l")) - 1;;
    string mCPU = run_command("lscpu | grep 'Model name:'").substr(21);
    int mCores = std::stoi(run_command("lscpu | grep 'CPU(s):'").substr(21));
    int mThreads = std::stoi(run_command("lscpu | grep 'Thread(s) per core:'").substr(21)) * mCores;
    string mVolts = run_command("vcgencmd measure_volts core").substr(5);
    string mFreq = run_command("lscpu | grep 'CPU max MHz'").substr(21);
    string mTemp = run_command("vcgencmd measure_temp").substr(5);
    string mThrottle = run_command("vcgencmd get_throttled").substr(10);
    float mMemory = stoi(run_command("cat /proc/meminfo | grep MemTotal").substr(17, run_command("cat /proc/meminfo | grep MemTotal").size() - 2) ) / 1024.0 / 1024.0;

    cout << Colors::Bold::Green << " `.::///+:/-.        --///+//-:``   " << Colors::Bold::Red << mUsername << Colors::Reset << " @ " << Colors::Bold::Red << mHostname << endl;
    cout << Colors::Bold::Green << "`+oooooooooooo:   `+oooooooooooo:   " << Colors::Reset << "--------" << endl;
    cout << Colors::Bold::Green << " /oooo++//ooooo:  ooooo+//+ooooo.   " << Colors::Bold::Red << "Host"    << Colors::Reset << ":\t " << mDevice << endl;
    cout << Colors::Bold::Green << " `+ooooooo:-:oo-  +o+::/ooooooo:    " << Colors::Bold::Red << "OS"      << Colors::Reset << ":\t\t " << mOS << endl;
    cout << Colors::Bold::Green << "  `:oooooooo+``    `.oooooooo+-     " << Colors::Bold::Red << "Kernel"  << Colors::Reset << ":\t " << mKernel << endl;
    cout << Colors::Bold::Green << "    `:++ooo/.        :+ooo+/.`      " << Colors::Bold::Red << "Width"   << Colors::Reset << ":\t " << mBits << endl;
    cout << Colors::Bold::Red   << "       ...`  `.----.` ``..          " << Colors::Bold::Red << "Uptime"  << Colors::Reset << ":\t " << mUptime << endl;
    cout << Colors::Bold::Red   << "    .::::-``:::::::::.`-:::-`       " << Colors::Bold::Red << endl;
    cout << Colors::Bold::Red   << "   -:::-`   .:::::::-`  `-:::-      " << Colors::Bold::Red << "Packages"    << Colors::Reset << ":\t " << mPackages << " (dpkg)" << endl;
    cout << Colors::Bold::Red   << "  `::.  `.--.`  `` `.---.``.::`     " << Colors::Bold::Red << "Containers"  << Colors::Reset << ":\t " << mContainers << " (docker)" << endl;
    cout << Colors::Bold::Red   << "      .::::::::`  -::::::::` `      " << Colors::Bold::Red << endl;
    cout << Colors::Bold::Red   << ".::` .:::::::::- `::::::::::``::.   " << Colors::Bold::Red << "CPU"         << Colors::Reset << ":\t " << mCPU << endl;
    cout << Colors::Bold::Red   << "-:::` ::::::::::.  ::::::::::.`:::- " << Colors::Bold::Red << "Topology"    << Colors::Reset << ":\t " << mCores << "c" << mThreads << "t" << endl;
    cout << Colors::Bold::Red   << "::::  -::::::::.   `-::::::::  :::: " << Colors::Bold::Red << "Frequency"   << Colors::Reset << ":\t " << mFreq << " Mhz" << endl;
    cout << Colors::Bold::Red   << "-::-   .-:::-.``....``.-::-.   -::- " << Colors::Bold::Red << "Volts"       << Colors::Reset << ":\t " << mVolts << endl;
    cout << Colors::Bold::Red   << ".. ``       .::::::::.     `..`..   " << Colors::Bold::Red << "Temperature" << Colors::Reset << ": " << mTemp << endl;
    cout << Colors::Bold::Red   << "  -:::-`   -::::::::::`  .:::::`    " << Colors::Bold::Red << "Throttle"    << Colors::Reset << ":\t " << mThrottle << endl;
    cout << Colors::Bold::Red   << "  :::::::` -::::::::::` :::::::.    " << Colors::Bold::Red << "Memory"      << Colors::Reset << ":\t " << mMemory << " Gib" << endl;
    cout << Colors::Bold::Red   << "  .:::::::  -::::::::. ::::::::     " << Colors::Reset << endl;
    cout << Colors::Bold::Red   << "   `-:::::`   ..--.`   ::::::.      " << Colors::Reset << endl;
    cout << Colors::Bold::Red   << "     `...`  `...--..`  `...`        " << Colors::Reset << endl;
    cout << Colors::Bold::Red   << "           .::::::::::              " << Colors::Reset << endl;
    cout << Colors::Bold::Red   << "            `.-::::-`               " << Colors::Reset << endl;

    return 0;
}