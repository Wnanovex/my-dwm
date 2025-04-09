#!/bin/sh

# Define variables
battery_path="/sys/class/power_supply/BAT0"
battery_capacity=$(cat "$battery_path/capacity")
battery_status=$(cat "$battery_path/status")
icon=""
icon_color="#ffffff"

# Create function to update battery status
update_battery(){

	# Change battery icon when battery capacity change
	if [ $battery_capacity -ge 90 ]; then
		icon=" "
        elif [ $battery_capacity -ge 70 ]; then
		icon=" "
        elif [ $battery_capacity -ge 40 ]; then
		icon=" "
	elif [ $battery_capacity -ge 20 ]; then
                icon=" "
        else
                icon_color="#E83F25"
		icon=" "
        fi

	# Change battery icon and color when battery status is charging
	if [ "$battery_status" = "Charging" ] || [ "$battery_status" = "Not charging" ]; then
		icon_color="#3A7D44"
		icon="$icon"
	fi

	# Print battery status
	echo "[^c${icon_color}^${icon}^c#000000^${battery_capacity}%] "

}

# Run update_battery function
update_battery

