
// graphics/draw/MenuHandler.cpp

#define str_loramenu_back               "Back"
#define str_loramenu_device_role        "Device Role"
#define str_loramenu_radio_preset       "Radio Preset"
#define str_loramenu_frequency_slot     "Frequency Slot"
#define str_loramenu_lora_lora          "LoRa"
#define str_loramenu_lora_power         "Power"
#define str_loramenu_lora_dutycycle     "Duty Cycle"
#define str_loramenu_lora_region        "LoRa Region"
#define str_loramenu_powerauto          "Max Legal"
#define str_loramenu_txpower            "%lu dBm"

#define str_onbmsg_ok                   "OK"
#define str_onbmsg_gotit                "Got it!"

#define str_onbmsg_welcomemsg_tft       "Welcome to Meshtastic!\nSwipe to navigate and\nlong press to select\nor open a menu.";
#define str_onbmsg_welcomemsg_btn       "Welcome to Meshtastic!\nClick to navigate and\nlong press to select\nor open a menu.";
#define str_onbmsg_welcomemsg           "Welcome to Meshtastic!\nUse the Select button\nto open menus\nand make selections.";

#define str_regionpicker_back           "Back"
#define str_regionpicker_setloraregion  "Set the LoRa region"
#define str_regionpicker_loraregion     "LoRa Region"

#define str_rolepicker_back             "Back"
#define str_rolepicker_devicerole       "Device Role"

#define str_slotpicker_back             "Back"
#define str_slotpicker_slot0auto        "Slot 0 (Auto)"
#define str_slotpicker_slot_lu          "Slot %lu"
#define str_slotpicker_frequency_slot   "Frequency Slot"

#define str_presetpicker_back           "Back"

#define str_12hourpicker_back           "Back"
#define str_12hourpicker_12h            "12-hour"
#define str_12hourpicker_24h            "24-hour"
#define str_12hourpicker_timeformat     "Time Format"

#define str_confirmation_no             "No"
#define str_confirmation_yes            "Yes"            

#define str_clockpicker_back            "Back"
#define str_clockpicker_digital         "Digital"
#define str_clockpicker_analog          "Analog"
#define str_clockpicker_which_face      "Which Face?"

#define str_timezonepicker_back         "Back"
#define str_timezonepicker_picktimezone "Pick Timezone"

#define str_clockmenu_back              "Back"
#define str_clockmenu_clockface         "Clock Face"
#define str_clockmenu_timeformat        "Time Format"
#define str_clockmenu_timezone          "Timezone"
#define str_clockmenu_clockaction       "Clock Action"

#define str_responsemenu_back           "Back"
#define str_responsemenu_reply          "Reply"
#define str_responsemenu_viewchats      "View Chats"
#define str_responsemenu_unmutechannel  "Unmute Channel" 
#define str_responsemenu_mutechannel    "Mute Channel"
#define str_responsemenu_delete         "Delete"
#define str_responsemenu_readaloud      "Read Aloud";
#define str_responsemenu_messageaction  "Message Action"
#define str_responsemenu_message        "Message"

#define str_replymenu_back              "Back"
#define str_replymenu_withpreset        "With Preset"    
#define str_replymenu_withfreetext      "With Freetext"
#define str_replymenu_replytochannel    "Reply to Channel"
#define str_replymenu_replytodm         "Reply to DM"
#define str_replymenu_replytolastmsg    "Reply to Last Msg"

#define str_delmsgmenu_back             "Back"
#define str_delmsgmenu_deloldest        "Delete Oldest"
#define str_delmsgmenu_delthischat      "Delete This Chat"
#define str_delmsgmenu_delall           "Delete All"
#define str_delmsgmenu_delallchats      "Delete All Chats"
#define str_delmsgmenu_delmessages      "Delete Messages"
#define str_delmsgmenu_delallmessages   "Deleting all messages"
#define str_delmsgmenu_deloldestmessage "Deleting oldest message"
#define str_delmsgmenu_delallinthread   "Deleting all messages in this thread"

#define str_msgvmmenu_back              "Back"
#define str_msgvmmenu_viewallchats      "View All Chats"
#define str_msgvmmenu_selectconverstn   "Select Conversation"

#define str_homebasemenu_back           "Back"
#define str_homebasemenu_tempmute       "Temporarily Mute"
#define str_homebasemenu_unmute         "Unmute"
#define str_homebasemenu_tglebacklight  "Toggle Backlight"
#define str_homebasemenu_sleepscreen    "Sleep Screen"
#define str_homebasemenu_sendposition   "Send Position"
#define str_homebasemenu_sendnodeinfo   "Send Node Info"
#define str_homebasemenu_homeaction     "Home Action"
#define str_homebasemenu_home           "Home"
#define str_homebasemenu_positionsent   "Position\nSent"
#define str_homebasemenu_nodeinfosent   "Node Info\nSent"

#define str_txtmsgbasemenu_back         "Back"
#define str_txtmsgbasemenu_newprstmsg   "New Preset Msg"
#define str_txtmsgbasemenu_newfreetxt   "New Freetext Msg"
#define str_txtmsgbasemenu_msgaction    "Message Action"

#define str_sysbasemenu_back            "Back"
#define str_sysbasemenu_notifications   "Notifications"
#define str_sysbasemenu_displayoptions  "Display Options"
#define str_sysbasemenu_bluetooth       "Bluetooth"
#define str_sysbasemenu_bluetoothtgl    "Bluetooth Toggle"
#define str_sysbasemenu_wifitgl         "WiFi Toggle"
#define str_sysbasemenu_power           "Power"
#define str_sysbasemenu_rebootshutdwn   "Reboot/Shutdown"
#define str_sysbasemenu_testmenu        "Test Menu"
#define str_sysbasemenu_systemaction    "System Action"
#define str_sysbasemenu_system          "System"

#define str_favbasemenu_back            "Back"
#define str_favbasemenu_gotochat        "Go To Chat"
#define str_favbasemenu_newprst         "New Preset"
#define str_favbasemenu_newprstmsg      "New Preset Msg"
#define str_favbasemenu_newfreettext    "New Freetext Msg"
#define str_favbasemenu_traceroute      "Trace Route"
#define str_favbasemenu_removefav       "Remove Favorite"
#define str_favbasemenu_favaction       "Favorites Action"
#define str_favbasemenu_favorites       "Favorites"

#define str_posbasemenu_back            "Back"
#define str_posbasemenu_onofftgl        "On/Off Toggle"
#define str_posbasemenu_format          "Format"
#define str_posbasemenu_smartposition   "Smart Position"
#define str_posbasemenu_updateinterval  "Update Interval"
#define str_posbasemenu_broadcatintrvl  "Broadcast Interval"
#define str_posbasemenu_compass         "Compass"
#define str_posbasemenu_compasscalib    "Compass Calibrate"
#define str_posbasemenu_gpsaction       "GPS Action"

#define str_nodelistmenu_back           "Back"
#define str_nodelistmenu_ndactnsstngs   "Node Actions / Settings";
#define str_nodelistmenu_showlngshrtnm  "Show Long/Short Name";
#define str_nodelistmenu_resetnodedb    "Reset NodeDB"
#define str_nodelistmenu_nodeaction     "Node Action"

#define str_nodepicker_picknode         "Pick Node"
#define str_nodepicker_pickanode        "Pick A Node"

#define str_managenodemenu_back         "Back"
#define str_managenodemenu_unfavorite   "Unfavorite"
#define str_managenodemenu_favorite     "Favorite"
#define str_managenodemenu_unmutenotif  "Unmute Notifications"
#define str_managenodemenu_mutenotif    "Mute Notifications"
#define str_managenodemenu_traceroute   "Trace Route"
#define str_managenodemenu_keyverif     "Key Verification"
#define str_managenodemenu_unignore     "Unignore Node"
#define str_managenodemenu_ignore       "Ignore Node"

#define str_nodenamelgthmenu_back       "Back"
#define str_nodenamelgthmenu_long       "Long"
#define str_nodenamelgthmenu_short      "Short"
#define str_nodenamelgthmenu_nnlength   "Node Name Length"

#define str_resetdbmenu_back            "Back"
#define str_resetdbmenu_resetall        "Reset All"
#define str_resetdbmenu_preservefav     "Preserve Favorites"
#define str_resetdbmenu_confirmrst      "Confirm Reset NodeDB"

#define str_compassnorthmenu_back       "Back"
#define str_compassnorthmenu_dynamic    "Dynamic"
#define str_compassnorthmenu_fixedring  "Fixed Ring"
#define str_compassnorthmenu_freezehdg  "Freeze Heading"
#define str_compassnorthmenu_northdir   "North Directions?"

#define str_gpstglmenu_back             "Back"
#define str_gpstglmenu_enabled          "Enabled"
#define str_gpstglmenu_disabled         "Disabled"
#define str_gpstglmenu_togglegps        "Toggle GPS"

#define str_gpsformatmenu_back          "Back"
#define str_gpsformatmenu_decdeg        "Decimal Degrees"
#define str_gpsformatmenu_dms           "Degrees Minutes Seconds"
#define str_gpsformatmenu_gpsformat     "GPS Format"

#define str_gpssmartmenu_back           "Back"
#define str_gpssmartmenu_enabled        "Enabled"
#define str_gpssmartmenu_disabled       "Disabled"
#define str_gpssmartmenu_tglsmartpos    "Toggle Smart Position"
#define str_gpssmartmenu_smartpos       "Smrt Postn"

#define str_gpsupdintmenu_back          "Back"
#define str_gpsupdintmenu_8s            "8 seconds"
#define str_gpsupdintmenu_20s           "20 seconds"
#define str_gpsupdintmenu_40s           "40 seconds"
#define str_gpsupdintmenu_1m            "1 minute"
#define str_gpsupdintmenu_80s           "80 seconds"
#define str_gpsupdintmenu_2m            "2 minutes"
#define str_gpsupdintmenu_5m            "5 minutes"
#define str_gpsupdintmenu_10m           "10 minutes"
#define str_gpsupdintmenu_15m           "15 minutes"
#define str_gpsupdintmenu_30m           "30 minutes"
#define str_gpsupdintmenu_1h            "1 hour"
#define str_gpsupdintmenu_6h            "6 hours"
#define str_gpsupdintmenu_12h           "12 hours"
#define str_gpsupdintmenu_24h           "24 hours"
#define str_gpsupdintmenu_abo           "At Boot Only"
#define str_gpsupdintmenu_updintrvl     "Update Interval"

#define str_gpsposbrdcstmenu_back       "Back"
#define str_gpsposbrdcstmenu_1m         "1 minute"
#define str_gpsposbrdcstmenu_90s        "90 seconds"
#define str_gpsposbrdcstmenu_5m         "5 minutes"
#define str_gpsposbrdcstmenu_15m        "15 minutes"
#define str_gpsposbrdcstmenu_1h         "1 hour"
#define str_gpsposbrdcstmenu_2h         "2 hours"
#define str_gpsposbrdcstmenu_3h         "3 hours"
#define str_gpsposbrdcstmenu_4h         "4 hours"
#define str_gpsposbrdcstmenu_5h         "5 hours"
#define str_gpsposbrdcstmenu_6h         "6 hours"
#define str_gpsposbrdcstmenu_12h        "12 hours"
#define str_gpsposbrdcstmenu_18h        "18 hours"
#define str_gpsposbrdcstmenu_24h        "24 hours"
#define str_gpsposbrdcstmenu_36h        "36 hours"
#define str_gpsposbrdcstmenu_48h        "48 hours"
#define str_gpsposbrdcstmenu_72h        "72 hours"
#define str_gpsposbrdcstmenu_brdcstint  "Broadcast Interval"

#define str_bluetglmenu_back            "Back"
#define str_bluetglmenu_enabled         "Enabled"
#define str_bluetglmenu_disabled        "Disabled"
#define str_bluetglmenu_tglbluetooth    "Toggle Bluetooth"
#define str_bluetglmenu_bluetooth       "Bluetooth"

#define str_buzzmodemenu_allenabled     "All Enabled"
#define str_buzzmodemenu_alldisabled    "All Disabled"
#define str_buzzmodemenu_notifications  "Notifications"
#define str_buzzmodemenu_systemonly     "System Only"
#define str_buzzmodemenu_dmsonly        "DMs Only"
#define str_buzzmodemenu_notifyonly     "Notification Sounds"

#define str_brightnesspicker_back       "Back"
#define str_brightnesspicker_bcklghtp   "Backlight +"
#define str_brightnesspicker_bcklghtn   "Backlight -"
#define str_brightnesspicker_cntrstp    "Contrast +"
#define str_brightnesspicker_cntrstn    "Contrast -"
#define str_brightnesspicker_invert     "Invert"
#define str_brightnesspicker_brightnes  "Brightness"
#define str_brightnesspicker_low        "Low"
#define str_brightnesspicker_med        "Medium"
#define str_brightnesspicker_high       "High"

#define str_switchtomui_no              "No"
#define str_switchtomui_yes             "Yes"
#define str_switchtomui_switchtomui     "Switch to MUI?"

#define str_tftcolorpicker_back         "Back"
#define str_tftcolorpicker_default      "Default"
#define str_tftcolorpicker_mshtstcgreen "Meshtastic Green"
#define str_tftcolorpicker_yellow       "Yellow"
#define str_tftcolorpicker_red          "Red"
#define str_tftcolorpicker_orange       "Orange"
#define str_tftcolorpicker_purple       "Purple"
#define str_tftcolorpicker_blue         "Blue"
#define str_tftcolorpicker_teal         "Teal"
#define str_tftcolorpicker_cyan         "Cyan"
#define str_tftcolorpicker_ice          "Ice"
#define str_tftcolorpicker_pink         "Pink"
#define str_tftcolorpicker_white        "White"
#define str_tftcolorpicker_gray         "Gray"
#define str_tftcolorpicker_selectscrclr "Select Screen Color"

#define str_rebootmenu_back             "Back"
#define str_rebootmenu_confirm          "Confirm"
#define str_rebootmenu_rebootdevice     "Reboot Device?"
#define str_rebootmenu_reboot           "Reboot"
#define str_rebootmenu_rebooting        "Rebooting..."

#define str_shtdwnmenu_back             "Back"
#define str_shtdwnmenu_confirm          "Confirm"
#define str_shtdwnmenu_shtdwndevice     "Shutdown Device?"
#define str_shtdwnmenu_shutdown         "Shutdown"

#define str_removefavmenu_back          "Back"
#define str_removefavmenu_yes           "Yes"
#define str_removefavmenu_unfvrttnode   "Unfavorite This Node?\n"

#define str_traceroutemenu_nodetotrace  "Node to Trace"

#define str_testmenu_back               "Back"
#define str_testmenu_nmbrpicker         "Number Picker"
#define str_testmenu_showchirpy         "Show Chirpy"
#define str_testmenu_hidechirpy         "Hide Chirpy"
#define str_testmenu_testanounce        "Test Announce"
#define str_testmenu_hiddentestmenu     "Hidden Test Menu"

#define str_numbertestpicker            "Pick a number\n "

#define str_wifibasemenut_back          "Back"
#define str_wifibasemenut_wifitgl       "WiFi Toggle"
#define str_wifibasemenut_wifimenu      "WiFi Menu"

#define str_wifitglmenu_back            "Back"
#define str_wifitglmenu_wifidisabled    "WiFi Disabled"
#define str_wifitglmenu_wifienabled     "WiFi Enabled"
#define str_wifitglmenu_wifiactions     "WiFi Actions"

#define str_screenoptmenu_back          "Back"
#define str_screenoptmenu_brightness    "Brightness"
#define str_screenoptmenu_scrcolor      "Screen Color"
#define str_screenoptmenu_framvsblty    "Frame Visibility"
#define str_screenoptmenu_displyunit    "Display Units"
#define str_screenoptmenu_msgbubles     "Message Bubbles"
#define str_screenoptmenu_displayopt    "Display Options"

#define str_pwrmenu_back                "Back"
#define str_pwrmenu_reboot              "Reboot"
#define str_pwrmenu_shutdown            "Shutdown"
#define str_pwrmenu_switchtoui          "Switch to MUI"
#define str_pwrmenu_rebootshtdwnd       "Reboot / Shutdown"
#define str_pwrmenu_power               "Power"

#define str_keyvermenupicker            "Node to Verify"

#define str_keyverpromptver             "Verification: \n"
#define str_keyverpromptreject          "Reject"
#define str_keyverpromptaccept          "Accept"

#define str_frametglmenu_finnish        "Finish"
#define str_frametglmenu_shownl         "Show Node Lists"
#define str_frametglmenu_hidenl         "Hide Node Lists"
#define str_frametglmenu_shownllh       "Show NL - Last Heard"
#define str_frametglmenu_hidenllh       "Hide NL - Last Heard"
#define str_frametglmenu_shownlhs       "Show NL - Hops/Signal"
#define str_frametglmenu_hidenlhs       "Hide NL - Hops/Signal"
#define str_frametglmenu_showposlists   "Show Position Lists"
#define str_frametglmenu_hideposlists   "Hide Position Lists"
#define str_frametglmenu_shownldist     "Show NL - Distance"
#define str_frametglmenu_hidenldist     "Hide NL - Distance"
#define str_frametglmenu_shownlbear     "Show NL - Bearings"
#define str_frametglmenu_hidenlbear     "Hide NL - Bearings"
#define str_frametglmenu_showpos        "Show Position"
#define str_frametglmenu_hidepos        "Hide Position"
#define str_frametglmenu_showlora       "Show LoRa"
#define str_frametglmenu_hidelora       "Hide LoRa"
#define str_frametglmenu_showclock      "Show Clock"
#define str_frametglmenu_hideclock      "Hide Clock"
#define str_frametglmenu_showfav        "Show Favorites"
#define str_frametglmenu_hidefav        "Hide Favorites"
#define str_frametglmenu_hideenvtele    "Hide Env. Telemetry"
#define str_frametglmenu_showenvtele    "Show Env. Telemetry"
#define str_frametglmenu_hideaqtele     "Hide AQ Telemetry"
#define str_frametglmenu_showaqtele     "Show AQ Telemetry"
#define str_frametglmenu_hidepower      "Hide Power"
#define str_frametglmenu_showpower      "Show Power"
#define str_frametglmenu_showhideframes "Show/Hide Frames"

#define str_dispunitmenu_back           "Back"
#define str_dispunitmenu_metric         "Metric"
#define str_dispunitmenu_retard         "Imperial"
#define str_dispunitmenu_seldispunit    " Select display units"

#define str_msgbublmenu_back            "Back"
#define str_msgbublmenu_shoebbls        "Show Bubbles"
#define str_msgbublmenu_hidebbls        "Hide Bubbles"
#define str_msgbublmenu_msgbbls         "Message Bubbles"

#define str_throttlemsg                 "Too Many Attempts\nTry again in 60 seconds."

// graphics/draw/DebugRenderer.cpp

#define str_dbgrndr_client              "Client";
#define str_dbgrndr_app                 "App"
#define str_dbgrndr_nocon               "No %ss Connected"
#define str_dbgrndr_wifi                "WiFi"
#define str_dbgrndr_wifinc              "WiFi: Not Connected"
#define str_dbgrndr_wificc              "WiFi: Connected"
#define str_dbgrndr_wifinssid           "SSID Not Found"
#define str_dbgrndr_wifilost            "Connection Lost"
#define str_dbgrndr_wifiidle            "Idle ... Reconnecting"
#define str_dbgrndr_wififail            "Connection Failed"
#define str_dbgrndr_wifiunknown         "Unknown status: %d"

#define str_dbgrndr_up                  "Up: "
#define str_dbgrndr_usb                 "USB"
#define str_dbgrndr_chutil              "ChUtil:"
#define str_dbgrndr_chutil2             "ChUtil %2.0f%%"
#define str_dbgrndr_txpower             "Power: %ludBm*%lu%%"  
#define str_dbgrndr_lorainfo            "LoRa Info"
#define str_dbgrndr_lora                "LoRa"
#define str_dbgrndr_ble                 "BLE: %s"
#define str_dbgrndr_role                "Role: %s"
#define str_dbgrndr_freq                "Freq: %sMHz"
#define str_dbgrndr_freqs               "%sMHz (%d)"

#define str_dbgrndr_system              "System"
#define str_dbgrndr_heap                "Heap:"

#define str_dbgrndr_conble              "%s Connected (BLE)"
#define str_dbgrndr_conwifi             "%s Connected (WiFi)"
#define str_dbgrndr_conser              "%s Connected (Serial)"
#define str_dbgrndr_conint              "%s Connected (Internal)"
#define str_dbgrndr_conhttp             "%s Connected (HTTP)"
#define str_dbgrndr_coneth              "%s Connected (Ethernet)"

// graphics/draw/MessageRenderer.cpp

#define str_drawtxtmsgframe_msgtitle    "Messages"
#define str_drawtxtmsgframe_messages    "Messages"
#define str_drawtxtmsgframe_dm          "(DM)"

#define str_drawtxtmsgframe_times       "%us"
#define str_drawtxtmsgframe_timem       "%um"
#define str_drawtxtmsgframe_timeh       "%uh"
#define str_drawtxtmsgframe_timed       "%ud"

#define str_drawtxtmsgframe_stos        "%s to %s"

#define str_drawtxtmsgframe_alertfrom   "Alert Received from\n%s"
#define str_drawtxtmsgframe_alertrcvd   "Alert Received"
#define str_drawtxtmsgframe_msgfrom     "New Message from\n%s"
#define str_drawtxtmsgframe_newmsg      "New Message"
#define str_drawtxtmsgframe_nomsg       "No messages"

#define str_drawtxtmsgframe_inns        "in #%s"
#define str_drawtxtmsgframe_inch        "in Ch%d"

// graphics/draw/NodeListRenderer.cpp

#define str_getcurmodtit_lastheard      "Last Heard"
#define str_getcurmodtit_hopsig         "Hops/Sig"
#define str_getcurmodtit_hopssignal     "Hops/Signal"
#define str_getcurmodtit_hopssig        "Hops/Sig"
#define str_getcurmodtit_nodes          "Nodes"

#define str_getcurmodtit_distance       "Distance"
#define str_getcurmodtit_bears          "Bearings"

#define str_getcurmodtit_d              "d"
#define str_getcurmodtit_h              "h"
#define str_getcurmodtit_m              "m"

#define str_drawnodeinfo_2distft        "%dft"
#define str_drawnodeinfo_2distmi        "¼mi"
#define str_drawnodeinfo_2distmi2       "%dmi"
#define str_drawnodeinfo_2distm         "%dm"
#define str_drawnodeinfo_2distkm        "1k"
#define str_drawnodeinfo_2distkm2       "%dk"

#define str_scrollpopupoverlay          "%d-%d/%d  Pg %d/%d"

// graphics/draw/NotificationRenderer.cpp

#define str_sslscreen_msg               "Creating SSL certificate"
#define str_sslscreen_wait1             "Please wait . . ."
#define str_sslscreen_wait2             "Please wait . .  "

#define str_drawnotifybox_signal        "Signal:"
#define str_drawnotifybox_alert         "Alert Received"

#define str_drawcritical_fault          "Critical fault #%d"
#define str_drawcritical_help           "For help, please visit \nmeshtastic.org"
#define str_drawcritical_update         "Updating"
#define str_drawcritical_please         "Please be patient and do not power off."

// graphics/draw/UIRenderer.cpp

#define str_drawgps_fixed               "Fixed"
#define str_drawgps_nolock              "No Lock"
#define str_drawgps_nosats              "No Sats"
#define str_drawgps_xsats               "%u sats"

#define str_drawgps_nogps               "No GPS"
#define str_drawgps_gpsoff              "GPS off"
#define str_drawgps_gpsnotpresent       "GPS not present"
#define str_drawgps_gpsdisabled         "GPS is disabled"

#define str_drawgps_altretard           "Altitude: %.0fft"
#define str_drawgps_altmeters           "Altitude: %.0im"

#define str_drawgps_nogpspresent        "No GPS present"
#define str_drawgps_nogpslock           "No GPS Lock"
#define str_drawgps_nogpsmodule         "No GPS Module"

#define str_drawgps_declat              "Lat: %f"
#define str_drawgps_declon              "Lon: %f"
#define str_drawgps_altlat              "Lat: %2i° %2i' %2u\" %1c"
#define str_drawgps_altlon              "Lon: %3i° %2i' %2u\" %1c"

#define str_drawnodeinfo_sig            "%sSig:%s"
#define str_drawnodeinfo_good1          "Good"
#define str_drawnodeinfo_good2          "Good"
#define str_drawnodeinfo_good3          "Good"
#define str_drawnodeinfo_fair           "Fair"
#define str_drawnodeinfo_bad            "Bad"

#define str_drawnodeinfo_heard1         " Heard:?"
#define str_drawnodeinfo_heard2         "%sHeard:%d%c ago"

#define str_drawnodeinfo_d              "d"
#define str_drawnodeinfo_h              "h"
#define str_drawnodeinfo_m              "m"

#define str_drawnodeinfo_sup            "%sUp:"
#define str_drawnodeinfo_distft         "%sDistance:%dft"
#define str_drawnodeinfo_distmi         "%sDistance:¼mi"
#define str_drawnodeinfo_distmi2        "%sDistance:%dmi"
#define str_drawnodeinfo_distm          "%sDistance:%dm"
#define str_drawnodeinfo_distkm         "%sDistance:1km"
#define str_drawnodeinfo_distkm2        "%sDistance:%dkm"

#define str_drawnodeinfo_bat1           "%sBat:%d%% (%.2fV)"
#define str_drawnodeinfo_bat2           "%sBat:%d%%"
#define str_drawnodeinfo_bat3           "%sPlugged In (%.2fV)"
#define str_drawnodeinfo_bat4           "%sPlugged In"
#define str_drawnodeinfo_bat5           "%sBat:%.2fV"

#define str_drawdevfocused_home         "Home"

#define str_drawdevfocused_online       "online"
#define str_drawdevfocused_uptime       "Up: "

#define str_drawdevfocused_fixedgps     "Fixed GPS";
#define str_drawdevfocused_nogps        "No GPS"
#define str_drawdevfocused_gpsoff       "GPS off"

#define str_drawdevfocused_bat6         "%01d.%02dV"
#define str_drawdevfocused_usb          "USB"
#define str_drawdevfocused_chutil       "Util"
#define str_drawdevfocused_btoff        "BT off"

#define str_einkdeepsleep_sleeping      "Sleeping"
#define str_einkdeepsleep_paused        "Screen Paused"

#define str_drawiconscreen_tasticurl    "meshtastic.org"

#define str_drawcompaslocscreen_pos     "Position"
#define str_drawcompaslocscreen_last    "Last: "
#define str_drawcompaslocscreen_last2   "Last: ?"

#define str_drawtimedelta_d             "d"
#define str_drawtimedelta_h             "h"
#define str_drawtimedelta_m             "m"
#define str_drawtimedelta_s             "s"

// modules/CannedMessageModule.cpp

#define str_launchwithdest_selectdest   "[Select Destination]"
#define str_launchwithdest_freetext     "[-- Free Text --]"

#define str_drawheader_to1              "To: #%s"
#define str_drawheader_to2              "To: @%s"

#define str_handlmsgselectinput_exit    "[Exit]"
#define str_handlmsgselectinput_sendmsg "Send message?"

#define str_sendtext_sending            "Sending..."

#define str_drawdestselscr_selectdest   "Select Destination"

#define str_drawframe_carleft           "%d left"
#define str_drawframe_destshift         "Dest: Shift + "

#define str_getsiggrade_good1           "Good"
#define str_getsiggrade_good2           "Good"
#define str_getsiggrade_good3           "Good"
#define str_getsiggrade_fair            "Fair"
#define str_getsiggrade_bad             "Bad"

#define str_hndlreceived_msgsent        "Message sent to\n#%s\n\nSignal: %s"
#define str_hndlreceived_dmsent         "DM sent to\n@%s\n\nSignal: %s"
#define str_hndlreceived_dmrelayed      "DM Relayed\n(Status Unknown)\n%s\n\nSignal: %s"
#define str_hndlreceived_msgfailed      "Message failed to\n#%s"
#define str_hndlreceived_dmfailed       "DM failed to\n@%s"

#define str_defaultcanmsg_msg           "Hi|Bye|Yes|No|Ok"

// modules/DetectionSensorModule.cpp

#define str_senddetectmsg_detected      "%s detected"
#define str_senddetectmsg_state         "%s state: %i"

// platform/nrf52/NRF52Bluetooth.cpp
// nimbe/NimbleBluetooth.cpp

#define str_onpairpass_bluetooth        "Bluetooth"
#define str_onpairpass_entercode        "Enter this code"

// motion/MotionSensor.cpp

#define str_framecalibration_cal        "Cal"
#define str_framecalibration_8          "Figure-8"
#define str_framecalibration_rotateax   "Rotate axes"
#define str_framecalibration_awayfrom   "Away from metal"
#define str_framecalibration_compcalib  "Compass Calibration"
#define str_framecalibration_movein8    "Move in figure-8"
#define str_framecalibration_rotateall  "Rotate all axes"
#define str_framecalibration_keetfrom   "Keep from metal"
#define str_framecalibration_compascal  "Compass Cal"
#define str_framecalibration_moveinfig  "Move in figure-8"
#define str_framecalibration_rotatealax "Rotate all axes"
#define str_framecalibration_frommetal  "Keep from metal"

#define str_framecalibration_000leftft  "000s left"
#define str_framecalibration_usleft     "%lus left"
#define str_framecalibration_us         "%lus"

// modules/WaypointModule.cpp

#define str_waypointdrawframe_wp        "Waypoint"

// modules/TraceRouteModule.cpp

#define str_alterRecievedpb_db          "dB)"
#define str_printroute_db1              "0x%x (%.2fdB) --> "
#define str_printroute_db2              "0x%x (?dB) --> "
#define str_printroute_db3              "0x%x (%.2fdB)"
#define str_printroute_db4              "0x%x (?dB)"
#define str_printroute_db5              "(%.2fdB) 0x%x <-- "
#define str_printroute_db6              "(?dB) 0x%x <-- "

#define str_starttrace_invalid          "Invalid node"
#define str_starttrace_cantself         "Cannot trace self"

#define str_tracecolldwn_wait           "Wait for "
#define str_tracecolldwn_s              "s"
#define str_tracecolldwn_tracing        "Tracing "
#define str_tracecolldwn_failed         "Failed to send"
#define str_tracecolldwn_unavailable    "Service unavailable"
#define str_tracecolldwn_noresponse     "No response received"
#define str_tracecolldwn_result         "Route Result"

// modules/telemetry/PowerTelemetry.cpp

#define str_powerteledraw_pwrtele       "Power Telem."
#define str_powerteledraw_pwr           "Power"
#define str_powerteledraw_nomeasure     "No measurement"
#define str_powerteledraw_measureerr    "Measurement Error"
#define str_powerteledraw_powfrom       "Pow. From: %s (%us)"
#define str_powerteledraw_values        "%s: %.2fV %.0fmA"

// modules/telemetry/HealthTelemetry.cpp

#define str_healthteledraw_health       "Health"
#define str_healthteledraw_nomeasure    "No measurement"
#define str_healthteledraw_measureerr   "Measurement Error"
#define str_healthteledraw_healthfrom   "Health From: %s(%ds)"
#define str_healthteledraw_temp         "Temp: %s"
#define str_healthteledraw_heart        "Heart Rate: %u bpm"
#define str_healthteledraw_spo2         "spO2: %u %%"

// modules/telemetry/EnvironmentTelemetry.cpp

#define str_envdrawframe_environment    "Environment"
#define str_envdrawframe_env            "Env."
#define str_envdrawframe_notele         "No Telemetry"
#define str_envdrawframe_h              "h"
#define str_envdrawframe_m              "m"
#define str_envdrawframe_s              "s";
#define str_envdrawframe_temp           "Tmp: "
#define str_envdrawframe_hum            "Hum: "
#define str_envdrawframe_prss           "Prss: "
#define str_envdrawframe_hpa            " hPa"
#define str_envdrawframe_iaq            "IAQ: "

#define str_envdrawframe_excellenet     " (Excellent)"
#define str_envdrawframe_good           " (Good)"
#define str_envdrawframe_moderate       " (Moderate)"
#define str_envdrawframe_poor           " (Poor)"
#define str_envdrawframe_unhealthy      " (Unhealthy)"
#define str_envdrawframe_unhiaq         "Unhealthy IAQ"
#define str_envdrawframe_veryunhealthy  " (Very Unhealthy)"
#define str_envdrawframe_veryunhiaq     "Very Unhealthy IAQ"
#define str_envdrawframe_hazard         " (Hazardous)"
#define str_envdrawframe_hazardiaq      "Hazardous IAQ"

#define str_envdrawframe_v              "V / "
#define str_envdrawframe_ma             "mA"
#define str_envdrawframe_light          "Light: "
#define str_envdrawframe_lx             "lx"
#define str_envdrawframe_white          "White: "
#define str_envdrawframe_weight         "Weight: "
#define str_envdrawframe_kg             "kg"
#define str_envdrawframe_level          "Level: "
#define str_envdrawframe_mm             "mm"
#define str_envdrawframe_rad            "Rad: "
#define str_envdrawframe_urh            " µR/h"

// modules/SystemCommandsModule.cpp

#define str_syscommodule_notifydisabled "Notifications\nDisabled"
#define str_syscommodule_notifyenabled  "Notifications\nEnabled"
#define str_syscommodule_btoffreboot    "Bluetooth OFF\nRebooting"
#define str_syscommodule_btonrebbot     "Bluetooth ON\nRebooting"
#define str_syscommodule_btoff          "Bluetooth OFF"
#define str_syscommodule_rebbot         "Rebooting..."
#define str_syscommodule_gpson          "GPS Enabled"
#define str_syscommodule_gpsoff         "GPS Disabled"
#define str_syscommodule_possent        "Position\nSent"
#define str_syscommodule_infosent       "Node Info\nSent"

// modules/ReplyModule.cpp

#define str_replymodule_recv            "Message Received"

// graphics/TimeFormatters.cpp

#define str_timeagostr_sa               "%u seconds ago"
#define str_timeagostr_ma               "%u minutes ago"
#define str_timeagostr_ls               "Last seen: %02u:%02u"
#define str_timeagostr_sy               "Seen yesterday"
#define str_timeagostr_da               "%li days ago"
#define str_timeagostr_ha               "%u hours ago"
#define str_timeagostr_un               "unknown age"

#define str_uptimestr_dh                "%s%ud %uh"
#define str_uptimestr_hm                "%s%uh %um"
#define str_uptimestr_m                 "%s%um"
#define str_uptimestr_ms                "%s%um %us"
#define str_uptimestr_s                 "%s%us"

// graphics/Screen.cpp

#define str_showtxtinput_txinput        "Text Input"
#define str_runonce_rebooting           "Rebooting..."
#define str_hndltxtmsg_msg              "Message"
#define str_hndltxtmsg_alertfrom        "Alert Received from\n%s"
#define str_hndltxtmsg_alert            "Alert Received"
#define str_hndltxtmsg_msgfrom          "New Message from\n%s"
#define str_hndltxtmsg_newmsg           "New Message"
