### Powershell 5
# Check if available
Get-WindowsCapability -Name RSAT.ActiveDirectory.DS-LDS.Tools* -online
# Install
Get-WindowsCapability -Name RSAT.ActiveDirectory.DS-LDS.Tools* -online | Add-WindowsCapability -Online
Get-WindowsCapability -Name RSAT* -Online | Add-WindowsCapability -Online
