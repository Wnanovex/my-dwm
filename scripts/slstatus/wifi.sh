#!/bin/sh

# Define variables
wifi_name=$(nmcli dev status | awk NR==2'{print $4}')
status=$(nmcli dev status | awk NR==2'{print $3}')
device=$(nmcli dev status | awk NR==2'{print $1}')
wifi_perc=$(nmcli -f IN-USE,SIGNAL dev wifi | grep '*' | awk '{print $2}')
icon=" "

# Create function to update wifi status
update_wifi(){

	# Check wifi status is connected and device is wlp0s20f3 then print wifi connected status or print wifi disconnected status
	if [ "$status" = "connected" ] && [ "$device" = "wlp0s20f3" ]; then
		echo "^b#EB5A3C^^c#000000^[^c#27445D^${icon}^c#000000^ ${wifi_name} ${wifi_perc}%] "
	else
		icon="$icon❌"
		echo "^b#EB5A3C^^c#000000^[^c#27445D^${icon}^c#000000^ Not connected] "
	fi

}

# Run update_wifi function
update_wifi

