#!/bin/sh

# Define variables
brightness=$(brightnessctl -m | awk -F, '{printf "%.0f", ($3/$5)*100}')
icon="󰖨 "
icon_color="#ffffff"

# Create function to update brightness status
update_brightness(){

	# Change brightness icon color when brightness value change
	if [ $brightness -ge 70 ]; then
                icon_color="#FFEB00"
        elif [ $brightness -ge 30 ]; then
                icon_color="#FFD95F"
        else
                icon_color="#EA7300"
        fi

	# Print brightness status
	echo "[^c${icon_color}^${icon}^c#000000^${brightness}%] "

}

# Run update_brightness function
update_brightness

