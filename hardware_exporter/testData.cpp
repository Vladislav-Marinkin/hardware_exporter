#include "testData.h"

std::string testData::getSsacliControllerTestData() const {
    return R"(

Smart Array P420i in Slot 0 (Embedded)
   Bus Interface: PCI
   Slot: 0
   Serial Number: 001438032CB5970
   Cache Serial Number: PBKUC0ARH2B2QR
   RAID 6 (ADG) Status: Enabled
   Controller Status: OK
   Hardware Revision: B
   Firmware Version: 8.32-0
   Firmware Supports Online Firmware Activation: False
   Rebuild Priority: Low
   Expand Priority: Medium
   Surface Scan Delay: 15 secs
   Surface Scan Mode: Idle
   Parallel Surface Scan Supported: No
   Queue Depth: Automatic
   Monitor and Performance Delay: 60  min
   Elevator Sort: Enabled
   Degraded Performance Optimization: Disabled
   Inconsistency Repair Policy: Disabled
   Wait for Cache Room: Disabled
   Surface Analysis Inconsistency Notification: Disabled
   Post Prompt Timeout: 0 secs
   Cache Board Present: True
   Cache Status: Permanently Disabled
   Cache Status Details: Cache disabled; backup power source failed to charge to an acceptable level
   Cache Disable Reason: Permanent disable condition. The posted write cache has been disabled because the backup power source attached to the flash-backed write cache module has failed to charge.
   Drive Write Cache: Disabled
   Total Cache Size: 1.0
   Total Cache Memory Available: 0.8
   No-Battery Write Cache: Disabled
   SSD Caching RAID5 WriteBack Enabled: False
   SSD Caching Version: 1
   Cache Backup Power Source: Capacitors
   Battery/Capacitor Count: 1
   Battery/Capacitor Status: Failed (Replace Batteries)
   SATA NCQ Supported: True
   Spare Activation Mode: Activate on physical drive failure (default)
   Controller Temperature (C): 88
   Cache Module Temperature (C): 38
   Capacitor Temperature  (C): 33
   Number of Ports: 2 Internal only
   Encryption: Not Set
   Driver Name: hpsa
   Driver Version: 3.4.20
   Driver Supports SSD Smart Path: True
   PCI Address (Domain:Bus:Device.Function): 0000:02:00.0
   Port Max Phy Rate Limiting Supported: False
   Host Serial Number: USE447ETRH
   Sanitize Erase Supported: False
   Primary Boot Volume: None
   Secondary Boot Volume: None

)";
}

std::string testData::getLSIControllerTestData() const
{
    return R"(
                                     

Adapter 0 -- Virtual Drive Information:
Virtual Drive: 0 (Target Id: 0)
Name                :vd0
RAID Level          : Primary-1, Secondary-0, RAID Level Qualifier-0
Size                : 2.792 TB
Sector Size         : 512
Is VD emulated      : No
Mirror Data         : 2.792 TB
State               : Optimal
Strip Size          : 128 KB
Number Of Drives per span:2
Span Depth          : 3
Default Cache Policy: WriteBack, ReadAhead, Direct, No Write Cache if Bad BBU
Current Cache Policy: WriteBack, ReadAhead, Direct, No Write Cache if Bad BBU
Default Access Policy: Read/Write
Current Access Policy: Read/Write
Disk Cache Policy   : Disk's Default
Encryption Type     : None
Bad Blocks Exist: No
PI type: No PI

Is VD Cached: No



Exit Code: 0x00
)";
}

std::string testData::getSsacliDiskTestData() const
{
    return R"(
Smart Array P420i in Slot 0 (Embedded)

   Array A

      physicaldrive 1I:1:1
         Port: 1I
         Box: 1
         Bay: 1
         Status: OK
         Drive Type: Data Drive
         Interface Type: SAS
         Size: 1.2 TB
         Drive exposed to OS: False
         Logical/Physical Block Size: 512/512
         Rotational Speed: 10500
         Firmware Revision: CDB0
         Serial Number: 06JEH70B
         WWID: 5000CCA02D8943F5
         Model: HGST    HUC101812CSS204
         Current Temperature (C): 39
         PHY Count: 2
         PHY Transfer Rate: 6.0Gbps, Unknown
         PHY Physical Link Rate: Unknown, Unknown
         PHY Maximum Link Rate: Unknown, Unknown
         Drive Authentication Status: OK
         Carrier Application Version: 11
         Carrier Bootloader Version: 6
         Sanitize Erase Supported: True
         Unrestricted Sanitize Supported: True
         Shingled Magnetic Recording Support: None

      physicaldrive 1I:1:2
         Port: 1I
         Box: 1
         Bay: 2
         Status: OK
         Drive Type: Data Drive
         Interface Type: SAS
         Size: 1.2 TB
         Drive exposed to OS: False
         Logical/Physical Block Size: 512/512
         Rotational Speed: 10500
         Firmware Revision: CDB0
         Serial Number: 06JEDD5B
         WWID: 5000CCA02D891969
         Model: HGST    HUC101812CSS204
         Current Temperature (C): 42
         PHY Count: 2
         PHY Transfer Rate: 6.0Gbps, Unknown
         PHY Physical Link Rate: Unknown, Unknown
         PHY Maximum Link Rate: Unknown, Unknown
         Drive Authentication Status: OK
         Carrier Application Version: 11
         Carrier Bootloader Version: 6
         Sanitize Erase Supported: True
         Unrestricted Sanitize Supported: True
         Shingled Magnetic Recording Support: None

      physicaldrive 1I:1:3
         Port: 1I
         Box: 1
         Bay: 3
         Status: OK
         Drive Type: Data Drive
         Interface Type: SAS
         Size: 1.2 TB
         Drive exposed to OS: False
         Logical/Physical Block Size: 512/512
         Rotational Speed: 10500
         Firmware Revision: CDB0
         Serial Number: 06JED87B
         WWID: 5000CCA02D891781
         Model: HGST    HUC101812CSS204
         Current Temperature (C): 37
         PHY Count: 2
         PHY Transfer Rate: 6.0Gbps, Unknown
         PHY Physical Link Rate: Unknown, Unknown
         PHY Maximum Link Rate: Unknown, Unknown
         Drive Authentication Status: OK
         Carrier Application Version: 11
         Carrier Bootloader Version: 6
         Sanitize Erase Supported: True
         Unrestricted Sanitize Supported: True
         Shingled Magnetic Recording Support: None

      physicaldrive 1I:1:4
         Port: 1I
         Box: 1
         Bay: 4
         Status: OK
         Drive Type: Data Drive
         Interface Type: SAS
         Size: 1.2 TB
         Drive exposed to OS: False
         Logical/Physical Block Size: 512/512
         Rotational Speed: 10500
         Firmware Revision: CDB0
         Serial Number: 06JEDDHB
         WWID: 5000CCA02D891991
         Model: HGST    HUC101812CSS204
         Current Temperature (C): 39
         PHY Count: 2
         PHY Transfer Rate: 6.0Gbps, Unknown
         PHY Physical Link Rate: Unknown, Unknown
         PHY Maximum Link Rate: Unknown, Unknown
         Drive Authentication Status: OK
         Carrier Application Version: 11
         Carrier Bootloader Version: 6
         Sanitize Erase Supported: True
         Unrestricted Sanitize Supported: True
         Shingled Magnetic Recording Support: None

      physicaldrive 2I:1:5
         Port: 2I
         Box: 1
         Bay: 5
         Status: OK
         Drive Type: Data Drive
         Interface Type: SAS
         Size: 1.2 TB
         Drive exposed to OS: False
         Logical/Physical Block Size: 512/512
         Rotational Speed: 10500
         Firmware Revision: CDB0
         Serial Number: 06JEDNVB
         WWID: 5000CCA02D891D9D
         Model: HGST    HUC101812CSS204
         Current Temperature (C): 34
         PHY Count: 2
         PHY Transfer Rate: 6.0Gbps, Unknown
         PHY Physical Link Rate: Unknown, Unknown
         PHY Maximum Link Rate: Unknown, Unknown
         Drive Authentication Status: OK
         Carrier Application Version: 11
         Carrier Bootloader Version: 6
         Sanitize Erase Supported: True
         Unrestricted Sanitize Supported: True
         Shingled Magnetic Recording Support: None

      physicaldrive 2I:1:6
         Port: 2I
         Box: 1
         Bay: 6
         Status: Failed
         Last Failure Reason: Timeout
         Drive Type: Data Drive
         Interface Type: SAS
         Size: 1.2 TB
         Drive exposed to OS: False
         Logical/Physical Block Size: 512/512
         Rotational Speed: 10500
         Firmware Revision: CDB0
         Serial Number: 06JEJ0WB
         WWID: 5000CCA02D895001
         Model: HGST    HUC101812CSS204
         PHY Count: 2
         PHY Transfer Rate: 6.0Gbps, Unknown
         PHY Physical Link Rate: Unknown, Unknown
         PHY Maximum Link Rate: Unknown, Unknown
         Drive Authentication Status: Not Applicable
         Sanitize Erase Supported: False
         Shingled Magnetic Recording Support: None

)";
}

std::string testData::getLSIDiskTestData() const
{
    return R"(
                                     
Adapter #0

Enclosure Device ID: 252
Slot Number: 0
Drive's position: DiskGroup: 0, Span: 0, Arm: 0
Enclosure position: N/A
Device Id: 9
WWN: 5002538840218dab
Sequence Number: 2
Media Error Count: 0
Other Error Count: 7
Predictive Failure Count: 0
Last Predictive Failure Event Seq Number: 0
PD Type: SATA

Raw Size: 953.869 GB [0x773bd2b0 Sectors]
Non Coerced Size: 953.369 GB [0x772bd2b0 Sectors]
Coerced Size: 953.343 GB [0x772b0000 Sectors]
Sector Size:  512
Logical Sector Size:  512
Physical Sector Size:  512
Firmware state: Online, Spun Up
Commissioned Spare : No
Emergency Spare : No
Device Firmware Level: 2B6Q
Shield Counter: 0
Successful diagnostics completion on :  N/A
SAS Address(0): 0x4433221100000000
Connected Port Number: 0(path0) 
Inquiry Data: S252NX0H600627D     Samsung SSD 850 PRO 1TB                 EXM02B6Q
FDE Capable: Not Capable
FDE Enable: Disable
Secured: Unsecured
Locked: Unlocked
Needs EKM Attention: No
Foreign State: None 
Device Speed: 6.0Gb/s 
Link Speed: 6.0Gb/s 
Media Type: Solid State Device
Drive:  Not Certified
Drive Temperature :27C (80.60 F)
PI Eligibility:  No 
Drive is formatted for PI information:  No
PI: No PI
Drive's NCQ setting : Enabled
Port-0 :
Port status: Active
Port's Linkspeed: 6.0Gb/s 
Drive has flagged a S.M.A.R.T alert : No



Enclosure Device ID: 252
Slot Number: 1
Drive's position: DiskGroup: 0, Span: 0, Arm: 1
Enclosure position: N/A
Device Id: 10
WWN: 500253887017eae4
Sequence Number: 2
Media Error Count: 0
Other Error Count: 5
Predictive Failure Count: 0
Last Predictive Failure Event Seq Number: 0
PD Type: SATA

Raw Size: 953.869 GB [0x773bd2b0 Sectors]
Non Coerced Size: 953.369 GB [0x772bd2b0 Sectors]
Coerced Size: 953.343 GB [0x772b0000 Sectors]
Sector Size:  512
Logical Sector Size:  512
Physical Sector Size:  512
Firmware state: Online, Spun Up
Commissioned Spare : No
Emergency Spare : No
Device Firmware Level: 2B6Q
Shield Counter: 0
Successful diagnostics completion on :  N/A
SAS Address(0): 0x4433221101000000
Connected Port Number: 1(path0) 
Inquiry Data: S2BBNWAJ103167Z     Samsung SSD 850 PRO 1TB                 EXM02B6Q
FDE Capable: Not Capable
FDE Enable: Disable
Secured: Unsecured
Locked: Unlocked
Needs EKM Attention: No
Foreign State: None 
Device Speed: 6.0Gb/s 
Link Speed: 6.0Gb/s 
Media Type: Solid State Device
Drive:  Not Certified
Drive Temperature :27C (80.60 F)
PI Eligibility:  No 
Drive is formatted for PI information:  No
PI: No PI
Drive's NCQ setting : Enabled
Port-0 :
Port status: Active
Port's Linkspeed: 6.0Gb/s 
Drive has flagged a S.M.A.R.T alert : No



Enclosure Device ID: 252
Slot Number: 2
Drive's position: DiskGroup: 0, Span: 1, Arm: 0
Enclosure position: N/A
Device Id: 11
WWN: 500253887018a6aa
Sequence Number: 2
Media Error Count: 0
Other Error Count: 0
Predictive Failure Count: 0
Last Predictive Failure Event Seq Number: 0
PD Type: SATA

Raw Size: 953.869 GB [0x773bd2b0 Sectors]
Non Coerced Size: 953.369 GB [0x772bd2b0 Sectors]
Coerced Size: 953.343 GB [0x772b0000 Sectors]
Sector Size:  512
Logical Sector Size:  512
Physical Sector Size:  512
Firmware state: Online, Spun Up
Commissioned Spare : No
Emergency Spare : No
Device Firmware Level: 2B6Q
Shield Counter: 0
Successful diagnostics completion on :  N/A
SAS Address(0): 0x4433221102000000
Connected Port Number: 2(path0) 
Inquiry Data: S2BBNWAJ204415X     Samsung SSD 850 PRO 1TB                 EXM02B6Q
FDE Capable: Not Capable
FDE Enable: Disable
Secured: Unsecured
Locked: Unlocked
Needs EKM Attention: No
Foreign State: None 
Device Speed: 6.0Gb/s 
Link Speed: 6.0Gb/s 
Media Type: Solid State Device
Drive:  Not Certified
Drive Temperature :26C (78.80 F)
PI Eligibility:  No 
Drive is formatted for PI information:  No
PI: No PI
Drive's NCQ setting : Enabled
Port-0 :
Port status: Active
Port's Linkspeed: 6.0Gb/s 
Drive has flagged a S.M.A.R.T alert : No



Enclosure Device ID: 252
Slot Number: 3
Drive's position: DiskGroup: 0, Span: 1, Arm: 1
Enclosure position: N/A
Device Id: 12
WWN: 500253887018a149
Sequence Number: 2
Media Error Count: 0
Other Error Count: 5
Predictive Failure Count: 0
Last Predictive Failure Event Seq Number: 0
PD Type: SATA

Raw Size: 953.869 GB [0x773bd2b0 Sectors]
Non Coerced Size: 953.369 GB [0x772bd2b0 Sectors]
Coerced Size: 953.343 GB [0x772b0000 Sectors]
Sector Size:  512
Logical Sector Size:  512
Physical Sector Size:  512
Firmware state: Online, Spun Up
Commissioned Spare : Yes
Emergency Spare : Yes
Device Firmware Level: 4B6Q
Shield Counter: 0
Successful diagnostics completion on :  N/A
SAS Address(0): 0x4433221103000000
Connected Port Number: 3(path0) 
Inquiry Data: S2BBNWAJ203038Y     Samsung SSD 850 PRO 1TB                 EXM04B6Q
FDE Capable: Not Capable
FDE Enable: Disable
Secured: Unsecured
Locked: Unlocked
Needs EKM Attention: No
Foreign State: None 
Device Speed: 6.0Gb/s 
Link Speed: 6.0Gb/s 
Media Type: Solid State Device
Drive:  Not Certified
Drive Temperature :26C (78.80 F)
PI Eligibility:  No 
Drive is formatted for PI information:  No
PI: No PI
Drive's NCQ setting : Enabled
Port-0 :
Port status: Active
Port's Linkspeed: 6.0Gb/s 
Drive has flagged a S.M.A.R.T alert : No



Enclosure Device ID: 252
Slot Number: 4
Drive's position: DiskGroup: 0, Span: 2, Arm: 0
Enclosure position: N/A
Device Id: 13
WWN: 50025388a0a4d771
Sequence Number: 2
Media Error Count: 0
Other Error Count: 0
Predictive Failure Count: 0
Last Predictive Failure Event Seq Number: 0
PD Type: SATA

Raw Size: 953.869 GB [0x773bd2b0 Sectors]
Non Coerced Size: 953.369 GB [0x772bd2b0 Sectors]
Coerced Size: 953.343 GB [0x772b0000 Sectors]
Sector Size:  512
Logical Sector Size:  512
Physical Sector Size:  512
Firmware state: Online, Spun Up
Commissioned Spare : No
Emergency Spare : No
Device Firmware Level: 2B6Q
Shield Counter: 0
Successful diagnostics completion on :  N/A
SAS Address(0): 0x4433221104000000
Connected Port Number: 6(path0) 
Inquiry Data: S252NSAG403428W     Samsung SSD 850 PRO 1TB                 EXM02B6Q
FDE Capable: Not Capable
FDE Enable: Disable
Secured: Unsecured
Locked: Unlocked
Needs EKM Attention: No
Foreign State: None 
Device Speed: 6.0Gb/s 
Link Speed: 6.0Gb/s 
Media Type: Solid State Device
Drive:  Not Certified
Drive Temperature :25C (77.00 F)
PI Eligibility:  No 
Drive is formatted for PI information:  No
PI: No PI
Drive's NCQ setting : Enabled
Port-0 :
Port status: Active
Port's Linkspeed: 6.0Gb/s 
Drive has flagged a S.M.A.R.T alert : No



Enclosure Device ID: 252
Slot Number: 5
Drive's position: DiskGroup: 0, Span: 2, Arm: 1
Enclosure position: N/A
Device Id: 14
WWN: 500253887018a6ab
Sequence Number: 2
Media Error Count: 0
Other Error Count: 0
Predictive Failure Count: 0
Last Predictive Failure Event Seq Number: 0
PD Type: SATA

Raw Size: 953.869 GB [0x773bd2b0 Sectors]
Non Coerced Size: 953.369 GB [0x772bd2b0 Sectors]
Coerced Size: 953.343 GB [0x772b0000 Sectors]
Sector Size:  512
Logical Sector Size:  512
Physical Sector Size:  512
Firmware state: Online, Spun Up
Commissioned Spare : No
Emergency Spare : No
Device Firmware Level: 2B6Q
Shield Counter: 0
Successful diagnostics completion on :  N/A
SAS Address(0): 0x4433221105000000
Connected Port Number: 7(path0) 
Inquiry Data: S2BBNWAJ204416J     Samsung SSD 850 PRO 1TB                 EXM02B6Q
FDE Capable: Not Capable
FDE Enable: Disable
Secured: Unsecured
Locked: Unlocked
Needs EKM Attention: No
Foreign State: None 
Device Speed: 6.0Gb/s 
Link Speed: 6.0Gb/s 
Media Type: Solid State Device
Drive:  Not Certified
Drive Temperature :25C (77.00 F)
PI Eligibility:  No 
Drive is formatted for PI information:  No
PI: No PI
Drive's NCQ setting : Enabled
Port-0 :
Port status: Active
Port's Linkspeed: 6.0Gb/s 
Drive has flagged a S.M.A.R.T alert : No



Enclosure Device ID: 252
Slot Number: 6
Enclosure position: N/A
Device Id: 16
WWN: 5000CCA03613CD0F
Sequence Number: 1
Media Error Count: 0
Other Error Count: 0
Predictive Failure Count: 0
Last Predictive Failure Event Seq Number: 0
PD Type: SAS

Raw Size: 838.362 GB [0x68cb9e30 Sectors]
Non Coerced Size: 837.862 GB [0x68bb9e30 Sectors]
Coerced Size: 837.843 GB [0x68bb0000 Sectors]
Sector Size:  512
Logical Sector Size:  512
Physical Sector Size:  512
Firmware state: Unconfigured(good), Spun down
Device Firmware Level: C904
Shield Counter: 0
Successful diagnostics completion on :  N/A
SAS Address(0): 0x5000cca03613cd0d
SAS Address(1): 0x0
Connected Port Number: 4(path0) 
Inquiry Data: HGST    HUC101890CSS204 C90405GAWL4C            
FDE Capable: Not Capable
FDE Enable: Disable
Secured: Unsecured
Locked: Unlocked
Needs EKM Attention: No
Foreign State: None 
Device Speed: 12.0Gb/s 
Link Speed: 12.0Gb/s 
Media Type: Hard Disk Device
Drive:  Not Certified
Drive Temperature :31C (87.80 F)
PI Eligibility:  No 
Drive is formatted for PI information:  No
PI: No PI
Port-0 :
Port status: Active
Port's Linkspeed: 12.0Gb/s 
Port-1 :
Port status: Active
Port's Linkspeed: 12.0Gb/s 
Drive has flagged a S.M.A.R.T alert : No



Enclosure Device ID: 252
Slot Number: 7
Enclosure position: N/A
Device Id: 15
WWN: 5000CCA02E08D8EF
Sequence Number: 1
Media Error Count: 0
Other Error Count: 0
Predictive Failure Count: 0
Last Predictive Failure Event Seq Number: 0
PD Type: SAS

Raw Size: 838.362 GB [0x68cb9e30 Sectors]
Non Coerced Size: 837.862 GB [0x68bb9e30 Sectors]
Coerced Size: 837.843 GB [0x68bb0000 Sectors]
Sector Size:  512
Logical Sector Size:  512
Physical Sector Size:  4096
Firmware state: Unconfigured(good), Spun down
Device Firmware Level: C904
Shield Counter: 0
Successful diagnostics completion on :  N/A
SAS Address(0): 0x5000cca02e08d8ed
SAS Address(1): 0x0
Connected Port Number: 5(path0) 
Inquiry Data: HGST    HUC101890CS4204 C90404G4VUZA            
FDE Capable: Not Capable
FDE Enable: Disable
Secured: Unsecured
Locked: Unlocked
Needs EKM Attention: No
Foreign State: None 
Device Speed: 12.0Gb/s 
Link Speed: 12.0Gb/s 
Media Type: Hard Disk Device
Drive:  Not Certified
Drive Temperature :33C (91.40 F)
PI Eligibility:  No 
Drive is formatted for PI information:  No
PI: No PI
Port-0 :
Port status: Active
Port's Linkspeed: 12.0Gb/s 
Port-1 :
Port status: Active
Port's Linkspeed: 12.0Gb/s 
Drive has flagged a S.M.A.R.T alert : No




Exit Code: 0x00
)";
}

std::string testData::getAdaptecTestData() const
{
    return R"(
Controllers found: 1
----------------------------------------------------------------------
Controller information
----------------------------------------------------------------------
   Controller Status                        : Optimal
   Controller Mode                          : RAID (Expose RAW)
   Channel description                      : SAS/SATA
   Controller Model                         : Adaptec ASR8805
   Controller Serial Number                 : 5E136305836
   Controller World Wide Name               : 50000D17002CF100
   Controller Alarm                         : Enabled
   Physical Slot                            : 9
   Temperature                              : 62 C/ 143 F (Normal)
   Installed memory                         : 1024 MB
   Host bus type                            : PCIe
   Host bus speed                           : 8000 MHz
   Host bus link width                      : 8 bit(s)/link(s)
   Global task priority                     : High
   Performance Mode                         : Default/Dynamic
   PCI Device ID                            : 653
   Stayawake period                         : Disabled
   Spinup limit internal drives             : 0
   Spinup limit external drives             : 0
   Defunct disk drive count                 : 0
   NCQ status                               : Enabled
   Statistics data collection mode          : Disabled
   Monitor Log Severity Level               : Informational
   Global Max SAS Phy Link Rate             : 12 Gbps
   Verify Write Setting                     : Not Applicable
   Error Tunable Profile                    : Normal
   --------------------------------------------------------
   Cache Properties
   --------------------------------------------------------
   Controller Cache Preservation            : Disabled
   Global Physical Device Write Cache Policy: Enabled
   --------------------------------------------------------
   RAID Properties
   --------------------------------------------------------
   Logical devices/Failed/Degraded          : 1/0/0
   Copyback                                 : Disabled
   Automatic Failover                       : Enabled
   Background consistency check             : Disabled
   Background consistency check period      : 0
   --------------------------------------------------------
   Controller BIOS Setting Information
   --------------------------------------------------------
   Runtime BIOS                             : Enabled
   Array BBS Support                        : Enabled
   Physical Drives Displayed during POST    : Enabled
   Backplane Mode                           : SGPIO
   BIOS Halt on Missing Drive Count         : 255
   --------------------------------------------------------
   Controller Version Information
   --------------------------------------------------------
   BIOS                                     : 7.9-0 (33023)
   Firmware                                 : 7.9-0 (33023)
   Driver                                   : 1.2-1 (41010)
   Boot Flash                               : 7.9-0 (33023)
   CPLD (Load version/ Flash version)       : 6/ 10
   SEEPROM (Load version/ Flash version)    : 1/ 1
   FCT Custom Init String Version           : 0x0

   --------------------------------------------------------
   Controller Cache Backup Unit Information
   --------------------------------------------------------

    Overall Backup Unit Status              : Ready

         Backup Unit Type                   : AFM-700/700LP
         Non-Volatile Storage Status        : Ready
         Supercap Status                    : Ready

         -----------------------------------
         Supercap Information               
         -----------------------------------
         Current Temperature                : 28 deg C
         Threshold Temperature              : 51 deg C
         Life-time Temperature Recorded     
         (Min/Max)                          : 17 deg C/ 37 deg C

         Voltage(Present/Max)               : 4923 mV/ 5302 mV
         Life-time Max Voltage Recorded     : 5402 mV

         Current Drawn(Present/Max)         : -12 mA/ 560 mA
         Health                             : 96 percent
         Charge Level                       : 100 percent
         Estimated Life-time                : 5 Years, 0 Month
         Serial Number                      : 4A421D92E21

         Learn Status                       : Idle
         Next Scheduled Learn Cycle         : 281 hours

         Present Capacitance                : 288 farads
   --------------------------------------------------------
   Connector information
                   
   --------------------------------------------------------
   Connector #0                             
      Connector Name                        : CN0

      --------------------------------------
   Lane Information                         
      --------------------------------------
      Lane #0                               
         Channel ID                         : 0
         Device ID                          : 0
         SAS Address                        : 50000D17002CF100
         PHY Identifier                     : 3
         -----------------------------------
         Lane SAS Phy Information           
         -----------------------------------
            SAS Address                     : 50000D17002CF100
            Attached PHY Identifier         : 0
            Attached SAS Address            : 30000D17002CF103
            Negotiated Logical Link Rate    : PHY enabled - 6 Gbps

      Lane #1                               
         Channel ID                         : 0
         Device ID                          : 1
         SAS Address                        : 50000D17002CF100
         PHY Identifier                     : 2
         -----------------------------------
         Lane SAS Phy Information           
         -----------------------------------
            SAS Address                     : 50000D17002CF100
            Attached PHY Identifier         : 0
            Attached SAS Address            : 30000D17002CF102
            Negotiated Logical Link Rate    : PHY enabled - 6 Gbps

      Lane #2                               
         Channel ID                         : 0
         Device ID                          : 2
         SAS Address                        : 50000D17002CF100
         PHY Identifier                     : 0
         -----------------------------------
         Lane SAS Phy Information           
         -----------------------------------
            SAS Address                     : 50000D17002CF100
            Attached PHY Identifier         : 0
            Attached SAS Address            : 30000D17002CF100
            Negotiated Logical Link Rate    : PHY enabled - 6 Gbps

      Lane #3                               
         Channel ID                         : 0
         Device ID                          : 3
         SAS Address                        : 50000D17002CF100
         PHY Identifier                     : 1
         -----------------------------------
         Lane SAS Phy Information           
         -----------------------------------
            SAS Address                     : 50000D17002CF100
            Attached PHY Identifier         : 0
            Attached SAS Address            : 30000D17002CF101
            Negotiated Logical Link Rate    : PHY enabled - 6 Gbps


   Connector #1                             
      Connector Name                        : CN1

      --------------------------------------
   Lane Information                         
      --------------------------------------
      Lane #0                               
         Channel ID                         : 0
         Device ID                          : 4
         SAS Address                        : 50000D17002CF100
         PHY Identifier                     : 5
         -----------------------------------
         Lane SAS Phy Information           
         -----------------------------------
            SAS Address                     : 50000D17002CF100
            Attached PHY Identifier         : 0
            Attached SAS Address            : 30000D17002CF105
            Negotiated Logical Link Rate    : PHY enabled - 6 Gbps

      Lane #1                               
         Channel ID                         : 0
         Device ID                          : 5
         SAS Address                        : 50000D17002CF100
         PHY Identifier                     : 6
         -----------------------------------
         Lane SAS Phy Information           
         -----------------------------------
            SAS Address                     : 50000D17002CF100
            Attached PHY Identifier         : 0
            Attached SAS Address            : 30000D17002CF106
            Negotiated Logical Link Rate    : PHY enabled - 6 Gbps

      Lane #2                               
         Channel ID                         : 0
         Device ID                          : 6
         SAS Address                        : 50000D17002CF100
         PHY Identifier                     : 4
         -----------------------------------
         Lane SAS Phy Information           
         -----------------------------------
            SAS Address                     : 50000D17002CF100

      Lane #3                               
         Channel ID                         : 0
         Device ID                          : 7
         SAS Address                        : 50000D17002CF100
         PHY Identifier                     : 7
         -----------------------------------
         Lane SAS Phy Information           
         -----------------------------------
            SAS Address                     : 50000D17002CF100



----------------------------------------------------------------------
Logical device information
----------------------------------------------------------------------
Logical Device number 0
   Logical Device name                      : ld0
   Block Size of member drives              : 512 Bytes
   RAID level                               : 10
   Unique Identifier                        : 609B0630
   Status of Logical Device                 : Optimal
   Additional details                       : Quick initialized
   Size                                     : 2307062 MB
   Parity space                             : 2307072 MB
   Stripe-unit size                         : 256 KB
   Interface Type                           : Serial ATA
   Device Type                              : SSD
   Read-cache setting                       : Disabled
   Read-cache status                        : Off
   Write-cache setting                      : On when protected by battery/ZMM
   Write-cache status                       : On
   Partitioned                              : Yes
   Protected by Hot-Spare                   : No
   Bootable                                 : Yes
   Failed stripes                           : No
   Power settings                           : Disabled
   --------------------------------------------------------
   Logical Device segment information
   --------------------------------------------------------
   Group 0, Segment 0                       : Present (915715MB, SATA, SSD, Enclosure:0, Slot:0) PHDV703100P4960FGN
   Group 0, Segment 1                       : Present (915715MB, SATA, SSD, Enclosure:0, Slot:1) PHDV6481005A960FGN
   Group 1, Segment 0                       : Present (915715MB, SATA, SSD, Enclosure:0, Slot:2) PHDV64800244960FGN
   Group 1, Segment 1                       : Present (915715MB, SATA, SSD, Enclosure:0, Slot:3) PHDV70940009960FGN
   Group 2, Segment 0                       : Present (915715MB, SATA, SSD, Enclosure:0, Slot:4) PHDV703100KD960FGN
   Group 2, Segment 1                       : Present (915715MB, SATA, SSD, Enclosure:0, Slot:5) PHDV702201LV960FGN


----------------------------------------------------------------------
Physical Device information
----------------------------------------------------------------------
      Device #0
         Device is a Hard drive
         State                              : Online
         Block Size                         : 512 Bytes
         Supported                          : Yes
         Programmed Max Speed               : SATA 6.0 Gb/s
         Transfer Speed                     : SATA 6.0 Gb/s
         Reported Channel,Device(T:L)       : 0,0(0:0)
         Reported Location                  : Enclosure 0, Slot 0(Connector 0)
         Reported ESD(T:L)                  : 2,0(0:0)
         Vendor                             : ATA
         Model                              : INTEL SSDSC2BB96
         Firmware                           : 0101
         Serial number                      : PHDV703100P4960FGN
         Reserved Size                      : 265496 KB
         Used Size                          : 769024 MB
         Unused Size                        : 146432 MB
         Total Size                         : 915715 MB
         Write Cache                        : Enabled (write-back)
         FRU                                : None
         S.M.A.R.T.                         : No
         S.M.A.R.T. warnings                : 0
         Power State                        : Full rpm
         Supported Power States             : Full power,Powered off
         SSD                                : Yes
         Temperature                        : 29 C/ 84 F 
         NCQ status                         : Enabled
      ----------------------------------------------------------------
      Device Phy Information                
      ----------------------------------------------------------------
         Phy #0
            PHY Identifier                  : 0
            SAS Address                     : 30000D17002CF103
            Attached PHY Identifier         : 3
            Attached SAS Address            : 50000D17002CF100
      ----------------------------------------------------------------
      Runtime Error Counters                
      ----------------------------------------------------------------
         Hardware Error Count               : 0
         Medium Error Count                 : 0
         Parity Error Count                 : 0
         Link Failure Count                 : 0
         Aborted Command Count              : 0
         SMART Warning Count                : 0

      Device #1
         Device is a Hard drive
         State                              : Online
         Block Size                         : 512 Bytes
         Supported                          : Yes
         Programmed Max Speed               : SATA 6.0 Gb/s
         Transfer Speed                     : SATA 6.0 Gb/s
         Reported Channel,Device(T:L)       : 0,1(1:0)
         Reported Location                  : Enclosure 0, Slot 1(Connector 0)
         Reported ESD(T:L)                  : 2,0(0:0)
         Vendor                             : ATA
         Model                              : INTEL SSDSC2BB96
         Firmware                           : 0101
         Serial number                      : PHDV6481005A960FGN
         Reserved Size                      : 265496 KB
         Used Size                          : 769024 MB
         Unused Size                        : 146432 MB
         Total Size                         : 915715 MB
         Write Cache                        : Enabled (write-back)
         FRU                                : None
         S.M.A.R.T.                         : No
         S.M.A.R.T. warnings                : 0
         Power State                        : Full rpm
         Supported Power States             : Full power,Powered off
         SSD                                : Yes
         Temperature                        : 27 C/ 80 F 
         NCQ status                         : Enabled
      ----------------------------------------------------------------
      Device Phy Information                
      ----------------------------------------------------------------
         Phy #0
            PHY Identifier                  : 0
            SAS Address                     : 30000D17002CF102
            Attached PHY Identifier         : 2
            Attached SAS Address            : 50000D17002CF100
      ----------------------------------------------------------------
      Runtime Error Counters                
      ----------------------------------------------------------------
         Hardware Error Count               : 0
         Medium Error Count                 : 0
         Parity Error Count                 : 0
         Link Failure Count                 : 0
         Aborted Command Count              : 0
         SMART Warning Count                : 0

      Device #2
         Device is a Hard drive
         State                              : Online
         Block Size                         : 512 Bytes
         Supported                          : Yes
         Programmed Max Speed               : SATA 6.0 Gb/s
         Transfer Speed                     : SATA 6.0 Gb/s
         Reported Channel,Device(T:L)       : 0,2(2:0)
         Reported Location                  : Enclosure 0, Slot 2(Connector 0)
         Reported ESD(T:L)                  : 2,0(0:0)
         Vendor                             : ATA
         Model                              : INTEL SSDSC2BB96
         Firmware                           : 0101
         Serial number                      : PHDV64800244960FGN
         Reserved Size                      : 265496 KB
         Used Size                          : 769024 MB
         Unused Size                        : 146432 MB
         Total Size                         : 915715 MB
         Write Cache                        : Enabled (write-back)
         FRU                                : None
         S.M.A.R.T.                         : No
         S.M.A.R.T. warnings                : 0
         Power State                        : Full rpm
         Supported Power States             : Full power,Powered off
         SSD                                : Yes
         Temperature                        : 26 C/ 78 F 
         NCQ status                         : Enabled
      ----------------------------------------------------------------
      Device Phy Information                
      ----------------------------------------------------------------
         Phy #0
            PHY Identifier                  : 0
            SAS Address                     : 30000D17002CF100
            Attached PHY Identifier         : 0
            Attached SAS Address            : 50000D17002CF100
      ----------------------------------------------------------------
      Runtime Error Counters                
      ----------------------------------------------------------------
         Hardware Error Count               : 0
         Medium Error Count                 : 0
         Parity Error Count                 : 0
         Link Failure Count                 : 0
         Aborted Command Count              : 0
         SMART Warning Count                : 0

      Device #3
         Device is a Hard drive
         State                              : Online
         Block Size                         : 512 Bytes
         Supported                          : Yes
         Programmed Max Speed               : SATA 6.0 Gb/s
         Transfer Speed                     : SATA 6.0 Gb/s
         Reported Channel,Device(T:L)       : 0,3(3:0)
         Reported Location                  : Enclosure 0, Slot 3(Connector 0)
         Reported ESD(T:L)                  : 2,0(0:0)
         Vendor                             : ATA
         Model                              : INTEL SSDSC2BB96
         Firmware                           : 0101
         Serial number                      : PHDV70940009960FGN
         Reserved Size                      : 265496 KB
         Used Size                          : 769024 MB
         Unused Size                        : 146432 MB
         Total Size                         : 915715 MB
         Write Cache                        : Enabled (write-back)
         FRU                                : None
         S.M.A.R.T.                         : No
         S.M.A.R.T. warnings                : 0
         Power State                        : Full rpm
         Supported Power States             : Full power,Powered off
         SSD                                : Yes
         Temperature                        : 27 C/ 80 F 
         NCQ status                         : Enabled
      ----------------------------------------------------------------
      Device Phy Information                
      ----------------------------------------------------------------
         Phy #0
            PHY Identifier                  : 0
            SAS Address                     : 30000D17002CF101
            Attached PHY Identifier         : 1
            Attached SAS Address            : 50000D17002CF100
      ----------------------------------------------------------------
      Runtime Error Counters                
      ----------------------------------------------------------------
         Hardware Error Count               : 0
         Medium Error Count                 : 0
         Parity Error Count                 : 0
         Link Failure Count                 : 0
         Aborted Command Count              : 0
         SMART Warning Count                : 0

      Device #4
         Device is a Hard drive
         State                              : Online
         Block Size                         : 512 Bytes
         Supported                          : Yes
         Programmed Max Speed               : SATA 6.0 Gb/s
         Transfer Speed                     : SATA 6.0 Gb/s
         Reported Channel,Device(T:L)       : 0,4(4:0)
         Reported Location                  : Enclosure 0, Slot 4(Connector 1)
         Reported ESD(T:L)                  : 2,0(0:0)
         Vendor                             : ATA
         Model                              : INTEL SSDSC2BB96
         Firmware                           : 0101
         Serial number                      : PHDV703100KD960FGN
         Reserved Size                      : 265496 KB
         Used Size                          : 769024 MB
         Unused Size                        : 146432 MB
         Total Size                         : 915715 MB
         Write Cache                        : Enabled (write-back)
         FRU                                : None
         S.M.A.R.T.                         : No
         S.M.A.R.T. warnings                : 0
         Power State                        : Full rpm
         Supported Power States             : Full power,Powered off
         SSD                                : Yes
         Temperature                        : 26 C/ 78 F 
         NCQ status                         : Enabled
      ----------------------------------------------------------------
      Device Phy Information                
      ----------------------------------------------------------------
         Phy #0
            PHY Identifier                  : 0
            SAS Address                     : 30000D17002CF105
            Attached PHY Identifier         : 5
            Attached SAS Address            : 50000D17002CF100
      ----------------------------------------------------------------
      Runtime Error Counters                
      ----------------------------------------------------------------
         Hardware Error Count               : 0
         Medium Error Count                 : 0
         Parity Error Count                 : 0
         Link Failure Count                 : 0
         Aborted Command Count              : 0
         SMART Warning Count                : 0

      Device #5
         Device is a Hard drive
         State                              : Online
         Block Size                         : 512 Bytes
         Supported                          : Yes
         Programmed Max Speed               : SATA 6.0 Gb/s
         Transfer Speed                     : SATA 6.0 Gb/s
         Reported Channel,Device(T:L)       : 0,5(5:0)
         Reported Location                  : Enclosure 0, Slot 5(Connector 1)
         Reported ESD(T:L)                  : 2,0(0:0)
         Vendor                             : ATA
         Model                              : INTEL SSDSC2BB96
         Firmware                           : 0101
         Serial number                      : PHDV702201LV960FGN
         Reserved Size                      : 265496 KB
         Used Size                          : 769024 MB
         Unused Size                        : 146432 MB
         Total Size                         : 915715 MB
         Write Cache                        : Enabled (write-back)
         FRU                                : None
         S.M.A.R.T.                         : No
         S.M.A.R.T. warnings                : 0
         Power State                        : Full rpm
         Supported Power States             : Full power,Powered off
         SSD                                : Yes
         Temperature                        : 25 C/ 77 F 
         NCQ status                         : Enabled
      ----------------------------------------------------------------
      Device Phy Information                
      ----------------------------------------------------------------
         Phy #0
            PHY Identifier                  : 0
            SAS Address                     : 30000D17002CF106
            Attached PHY Identifier         : 6
            Attached SAS Address            : 50000D17002CF100
      ----------------------------------------------------------------
      Runtime Error Counters                
      ----------------------------------------------------------------
         Hardware Error Count               : 0
         Medium Error Count                 : 0
         Parity Error Count                 : 0
         Link Failure Count                 : 0
         Aborted Command Count              : 0
         SMART Warning Count                : 0

      Device #6
         Device is an Enclosure Services Device
         Reported Channel,Device(T:L)       : 2,0(0:0)
         Enclosure ID                       : 0
         Type                               : SES2
         Vendor                             : ADAPTEC
         Model                              : Virtual SGPIO
         Firmware                           :    1
         Status of Enclosure Services Device
            Speaker status                  : Not Available

----------------------------------------------------------------------
Connector information
----------------------------------------------------------------------
Connector #0                                
   Connector Name                           : CN0

      --------------------------------------
   Lane Information                         
      --------------------------------------
   Lane #0                                  
      Channel ID                            : 0
      Device ID                             : 0
      SAS Address                           : 50000D17002CF100
      PHY Identifier                        : 3
         -----------------------------------
      Lane SAS Phy Information              
         -----------------------------------
         SAS Address                        : 50000D17002CF100
         Attached PHY Identifier            : 0
         Attached SAS Address               : 30000D17002CF103
         Negotiated Logical Link Rate       : PHY enabled - 6 Gbps

   Lane #1                                  
      Channel ID                            : 0
      Device ID                             : 1
      SAS Address                           : 50000D17002CF100
      PHY Identifier                        : 2
         -----------------------------------
      Lane SAS Phy Information              
         -----------------------------------
         SAS Address                        : 50000D17002CF100
         Attached PHY Identifier            : 0
         Attached SAS Address               : 30000D17002CF102
         Negotiated Logical Link Rate       : PHY enabled - 6 Gbps

   Lane #2                                  
      Channel ID                            : 0
      Device ID                             : 2
      SAS Address                           : 50000D17002CF100
      PHY Identifier                        : 0
         -----------------------------------
      Lane SAS Phy Information              
         -----------------------------------
         SAS Address                        : 50000D17002CF100
         Attached PHY Identifier            : 0
         Attached SAS Address               : 30000D17002CF100
         Negotiated Logical Link Rate       : PHY enabled - 6 Gbps

   Lane #3                                  
      Channel ID                            : 0
      Device ID                             : 3
      SAS Address                           : 50000D17002CF100
      PHY Identifier                        : 1
         -----------------------------------
      Lane SAS Phy Information              
         -----------------------------------
         SAS Address                        : 50000D17002CF100
         Attached PHY Identifier            : 0
         Attached SAS Address               : 30000D17002CF101
         Negotiated Logical Link Rate       : PHY enabled - 6 Gbps


Connector #1                                
   Connector Name                           : CN1

      --------------------------------------
   Lane Information                         
      --------------------------------------
   Lane #0                                  
      Channel ID                            : 0
      Device ID                             : 4
      SAS Address                           : 50000D17002CF100
      PHY Identifier                        : 5
         -----------------------------------
      Lane SAS Phy Information              
         -----------------------------------
         SAS Address                        : 50000D17002CF100
         Attached PHY Identifier            : 0
         Attached SAS Address               : 30000D17002CF105
         Negotiated Logical Link Rate       : PHY enabled - 6 Gbps

   Lane #1                                  
      Channel ID                            : 0
      Device ID                             : 5
      SAS Address                           : 50000D17002CF100
      PHY Identifier                        : 6
         -----------------------------------
      Lane SAS Phy Information              
         -----------------------------------
         SAS Address                        : 50000D17002CF100
         Attached PHY Identifier            : 0
         Attached SAS Address               : 30000D17002CF106
         Negotiated Logical Link Rate       : PHY enabled - 6 Gbps

   Lane #2                                  
      Channel ID                            : 0
      Device ID                             : 6
      SAS Address                           : 50000D17002CF100
      PHY Identifier                        : 4
         -----------------------------------
      Lane SAS Phy Information              
         -----------------------------------
         SAS Address                        : 50000D17002CF100

   Lane #3                                  
      Channel ID                            : 0
      Device ID                             : 7
      SAS Address                           : 50000D17002CF100
      PHY Identifier                        : 7
         -----------------------------------
      Lane SAS Phy Information              
         -----------------------------------
         SAS Address                        : 50000D17002CF100



Command completed successfully.
)";
}

std::string testData::getFanDriveData() const
{
    return R"(
Fan Redundancy   | 0Ch | ok  | 30.1 | Fully Redundant
System Fan 1A    | 30h | ok  | 29.1 | 11352 RPM
System Fan 1B    | 31h | ok  | 29.2 | 10873 RPM
System Fan 2A    | 32h | ok  | 29.3 | 11180 RPM
System Fan 2B    | 33h | ok  | 29.4 | 10790 RPM
System Fan 3A    | 34h | ok  | 29.5 | 10922 RPM
System Fan 3B    | 35h | ok  | 29.6 | 10790 RPM
System Fan 4A    | 36h | ok  | 29.7 | 11094 RPM
System Fan 4B    | 37h | ok  | 29.8 | 10790 RPM
System Fan 5A    | 38h | ok  | 29.9 | 11180 RPM
System Fan 5B    | 39h | ok  | 29.10 | 10790 RPM
System Fan 6A    | 3Ah | ok  | 29.11 | 11094 RPM
System Fan 6B    | 3Bh | ok  | 29.12 | 10790 RPM
PS1 Fan Fail     | A0h | ok  | 10.1 | 
PS2 Fan Fail     | A4h | ok  | 10.2 |
)";
}
