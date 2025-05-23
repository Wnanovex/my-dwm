/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cat                 read arbitrary file             path
 * cpu_freq            cpu frequency in MHz            NULL
 * cpu_perc            cpu usage in percent            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/)
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD/FreeBSD
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 */
static const struct arg args[] = {
	/* function     format          argument */
        { run_command,  "%s", "/home/$USER/my-dwm/scripts/slstatus/wifi.sh" },
        { cpu_perc,     "[^c#500073^ ^c#000000^CPU %s%%] ",      NULL},
        { ram_perc,     "[^c#003092^󰔶 ^c#000000^RAM %s%, ",         NULL},
        { ram_used,     "%sB] ",           NULL },
        { run_command,  "%s", "/home/$USER/my-dwm/scripts/slstatus/brightness.sh" },
        { run_command,  "%s", "/home/$USER/my-dwm/scripts/slstatus/battery.sh" },
        { run_command,  "%s", "/home/$USER/my-dwm/scripts/slstatus/volume.sh" },
	{ datetime,     "[ %s ]", "%a %d %b %Y %R" },
	//{ wifi_essid,   "^b#EB5A3C^^c#000000^[^c#27445D^ ^c#000000^ %s ",  "wlp0s20f3"},
        //{ wifi_perc,    "%s%] ",       "wlp0s20f3"},
	//{ netspeed_rx,  "^b#EB5A3C^^c#000000^ %s ] ",         "wlp0s20f3"},
        //{ run_command, "[^c#FFEB00^󰖨 ^c#000000^ %s] ",   "brightnessctl -m | awk -F, '{printf \"%.0f%%\", ($3/$5)*100}'"},
	//{ battery_perc, "[^c#3A7D44^ ^c#000000^ %s%] ",           "BAT0"},
	//{ run_command,  "[^c#344CB7^ ^c#000000^ %s] ", "pamixer --get-volume-human | awk {'print $1'}" },
};
