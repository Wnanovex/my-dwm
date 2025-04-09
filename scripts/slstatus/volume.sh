#!/bin/sh

# Define variables
volume=$(pamixer --get-volume)
volume_human=$(pamixer --get-volume-human)
is_muted=$(pamixer --get-mute)  # Returns "true" or "false"
icon=""
icon_color="#344CB7"

# Create function to update volume status
update_volume(){

	# Check volume is muted then change volume icon and it color
	if [ "$is_muted" = "true" ]; then
      		icon_color="#E52020"
        	icon="❌ "
    	else
		# Change volume icon when volume value change
        	if [ $volume -ge 50 ]; then
            		icon=" "
        	elif [ $volume -ge 30 ]; then
            		icon=" "
        	else
           		icon=" "
        	fi
    	fi

	# Print volume status
	echo "[^c${icon_color}^${icon}^c#000000^${volume_human}] "

}

# Run update_volume function
update_volume

