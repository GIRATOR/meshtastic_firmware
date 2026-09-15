
// graphics/draw/MenuHandler.cpp

#define str_loramenu_back               "Назад"
#define str_loramenu_device_role        "Роль прист."
#define str_loramenu_radio_preset       "Радіо шабл."
#define str_loramenu_frequency_slot     "Частот. кан."
#define str_loramenu_lora_lora          "ЛОРА"
#define str_loramenu_lora_region        "ЛОРА регіон"

#define str_onbmsg_ok                   "Добре"
#define str_onbmsg_gotit                "Зрозуміло!"

#define str_onbmsg_welcomemsg_tft       "Вітаємо в Мештастик!\nГорніть щоб перейти\nпотисніть щоб вибрати\nабо відкрити меню.";
#define str_onbmsg_welcomemsg_btn       "Вітаємо в Мештастик!\nКлацніть щоб перейти\nпотисніть щоб вибрати\nабо відкрити меню.";
#define str_onbmsg_welcomemsg           "Вітаємо в Мештастик!\nТисніть вибір\nщоб відкривати меню\nі вибирати.";

#define str_regionpicker_back           "Назад"
#define str_regionpicker_setloraregion  "Вибр. регіон"
#define str_regionpicker_loraregion     "ЛОРА регіон"

#define str_rolepicker_back             "Назад"
#define str_rolepicker_devicerole       "Роль пристрою"

#define str_slotpicker_back             "Назад"
#define str_slotpicker_slot0auto        "Кан. (авто)"
#define str_slotpicker_slot_lu          "Кан. %lu"
#define str_slotpicker_frequency_slot   "Частот. кан."

#define str_presetpicker_back           "Назад"

#define str_12hourpicker_back           "Назад"
#define str_12hourpicker_12h            "12-год"
#define str_12hourpicker_24h            "24-год"
#define str_12hourpicker_timeformat     "Формат часу"

#define str_confirmation_no             "Ні"
#define str_confirmation_yes            "Так"            

#define str_clockpicker_back            "Назад"
#define str_clockpicker_digital         "Цифровий"
#define str_clockpicker_analog          "Стрілковий"
#define str_clockpicker_which_face      "Вигл.год-ка"

#define str_timezonepicker_back         "Назад"
#define str_timezonepicker_picktimezone "Виб.час.пояс"

#define str_clockmenu_back              "Назад"
#define str_clockmenu_clockface         "Вигл.год-ка"
#define str_clockmenu_timeformat        "Формат часу"
#define str_clockmenu_timezone          "Час. пояс"
#define str_clockmenu_clockaction       "Годинник"

#define str_responsemenu_back           "Назад"
#define str_responsemenu_reply          "Відповісти"
#define str_responsemenu_viewchats      "Див. чати"
#define str_responsemenu_unmutechannel  "Розглуш.кан." 
#define str_responsemenu_mutechannel    "Приглуш.кан."
#define str_responsemenu_delete         "Видалити"
#define str_responsemenu_readaloud      "Озвучити";
#define str_responsemenu_messageaction  "Повідомлення"
#define str_responsemenu_message        "Повідомлення"

#define str_replymenu_back              "Назад"
#define str_replymenu_withpreset        "Коротка відп."    
#define str_replymenu_withfreetext      "Набір тексту"
#define str_replymenu_replytochannel    "Відп.в канал"
#define str_replymenu_replytodm         "Відп.в приват"
#define str_replymenu_replytolastmsg    "Відп.на остан."

#define str_delmsgmenu_back             "Назад"
#define str_delmsgmenu_deloldest        "Видал.старі"
#define str_delmsgmenu_delthischat      "Видал.цей чат"
#define str_delmsgmenu_delall           "Видал.все"
#define str_delmsgmenu_delallchats      "Видал.всі чати"
#define str_delmsgmenu_delmessages      "Видал.повідом."
#define str_delmsgmenu_delallmessages   "Видал.всі.пов."
#define str_delmsgmenu_deloldestmessage "Видал.старі.пов."
#define str_delmsgmenu_delallinthread   "Видал.цілу тему"

#define str_msgvmmenu_back              "Назад"
#define str_msgvmmenu_viewallchats      "Див.всі чати"
#define str_msgvmmenu_selectconverstn   "Обрати розмову"

#define str_homebasemenu_back           "Назад"
#define str_homebasemenu_tempmute       "Тимчас.приглуш."
#define str_homebasemenu_unmute         "Розглушити"
#define str_homebasemenu_tglebacklight  "Підсвітка ув/вим"
#define str_homebasemenu_sleepscreen    "Вимк. дисплей"
#define str_homebasemenu_sendposition   "Надісл.місцезнах."
#define str_homebasemenu_sendnodeinfo   "Надісл.інф.вузла"
#define str_homebasemenu_homeaction     "Домівка"
#define str_homebasemenu_home           "Домівка"
#define str_homebasemenu_positionsent   "Координати\nнадіслано"
#define str_homebasemenu_nodeinfosent   "Інфо вузла\nнадіслано"

#define str_txtmsgbasemenu_back         "Назад"
#define str_txtmsgbasemenu_newprstmsg   "Шаблон"
#define str_txtmsgbasemenu_newfreetxt   "Набрати текст"
#define str_txtmsgbasemenu_msgaction    "Повідомлення"

#define str_sysbasemenu_back            "Назад"
#define str_sysbasemenu_notifications   "Сповіщення"
#define str_sysbasemenu_displayoptions  "Нал.дисплею"
#define str_sysbasemenu_bluetooth       "Блютус"
#define str_sysbasemenu_bluetoothtgl    "Блютус ув/вим"
#define str_sysbasemenu_wifitgl         "Вай-ФАй ув/вим"
#define str_sysbasemenu_power           "Живлення"
#define str_sysbasemenu_rebootshutdwn   "Перезав./Вимк."
#define str_sysbasemenu_testmenu        "Тест меню"
#define str_sysbasemenu_systemaction    "Налаштування"
#define str_sysbasemenu_system          "Налаштування"

#define str_favbasemenu_back            "Назад"
#define str_favbasemenu_gotochat        "До чату"
#define str_favbasemenu_newprst         "Шаблон"
#define str_favbasemenu_newprstmsg      "Шаблон повід."
#define str_favbasemenu_newfreettext    "Набрати текст"
#define str_favbasemenu_traceroute      "Відстеж.шлях."
#define str_favbasemenu_removefav       "Розлюбити"
#define str_favbasemenu_favaction       "Улюблені"
#define str_favbasemenu_favorites       "Улюблені"

#define str_posbasemenu_back            "Назад"
#define str_posbasemenu_onofftgl        "Ув./Вимк."
#define str_posbasemenu_format          "Формат"
#define str_posbasemenu_smartposition   "Розум.позиція."
#define str_posbasemenu_updateinterval  "Період оновл."
#define str_posbasemenu_broadcatintrvl  "Період розсил."
#define str_posbasemenu_compass         "Компас"
#define str_posbasemenu_compasscalib    "Калібр. компас"
#define str_posbasemenu_gpsaction       "Глоб.нав.сист."

#define str_nodelistmenu_back           "Назад"
#define str_nodelistmenu_ndactnsstngs   "Меню вузла";
#define str_nodelistmenu_showlngshrtnm  "Довжина імен";
#define str_nodelistmenu_resetnodedb    "Скинути БД"
#define str_nodelistmenu_nodeaction     "Меню вузла"

#define str_nodepicker_picknode         "Виб. вузол"
#define str_nodepicker_pickanode        "Вибери вузол"

#define str_managenodemenu_back         "Назад"
#define str_managenodemenu_unfavorite   "Розлюбити"
#define str_managenodemenu_favorite     "Улюблений"
#define str_managenodemenu_unmutenotif  "Розглуш.сповіщ."
#define str_managenodemenu_mutenotif    "Приглуш.сповіщ."
#define str_managenodemenu_traceroute   "Відстеж.шлях."
#define str_managenodemenu_keyverif     "Повірка ключа"
#define str_managenodemenu_unignore     "Взяти до уваги"
#define str_managenodemenu_ignore       "Не помічати"

#define str_nodenamelgthmenu_back       "Назад"
#define str_nodenamelgthmenu_long       "Довге"
#define str_nodenamelgthmenu_short      "Коротке"
#define str_nodenamelgthmenu_nnlength   "Довжина ім'я"

#define str_resetdbmenu_back            "Назад"
#define str_resetdbmenu_resetall        "Скинути Всі"
#define str_resetdbmenu_preservefav     "Залиш. улюблені"
#define str_resetdbmenu_confirmrst      "Підтв.скид.БД"

#define str_compassnorthmenu_back       "Назад"
#define str_compassnorthmenu_dynamic    "Рухомий"
#define str_compassnorthmenu_fixedring  "Фікс. кільце"
#define str_compassnorthmenu_freezehdg  "закріп. напр."
#define str_compassnorthmenu_northdir   "Півн. напрям"

#define str_gpstglmenu_back             "Назад"
#define str_gpstglmenu_enabled          "Увімкнено"
#define str_gpstglmenu_disabled         "Вимкнено"
#define str_gpstglmenu_togglegps        "Глоб.нав.сист."

#define str_gpsformatmenu_back          "Назад"
#define str_gpsformatmenu_decdeg        "Дес. градуси"
#define str_gpsformatmenu_dms           "Град./Хв./Сек."
#define str_gpsformatmenu_gpsformat     "Формат ГНС"

#define str_gpssmartmenu_back           "Назад"
#define str_gpssmartmenu_enabled        "Увімкнено"
#define str_gpssmartmenu_disabled       "Вимкнено"
#define str_gpssmartmenu_tglsmartpos    "Розум.позиція."
#define str_gpssmartmenu_smartpos       "Розум.позиція."

#define str_gpsupdintmenu_back          "Назад"
#define str_gpsupdintmenu_8s            "8 секунд"
#define str_gpsupdintmenu_20s           "20 секунд"
#define str_gpsupdintmenu_40s           "40 секунд"
#define str_gpsupdintmenu_1m            "1 хвилина"
#define str_gpsupdintmenu_80s           "80 секунд"
#define str_gpsupdintmenu_2m            "2 хвилини"
#define str_gpsupdintmenu_5m            "5 хвилин"
#define str_gpsupdintmenu_10m           "10 хвилин"
#define str_gpsupdintmenu_15m           "15 хвилин"
#define str_gpsupdintmenu_30m           "30 хвилин"
#define str_gpsupdintmenu_1h            "1 година"
#define str_gpsupdintmenu_6h            "6 годин"
#define str_gpsupdintmenu_12h           "12 годин"
#define str_gpsupdintmenu_24h           "24 години"
#define str_gpsupdintmenu_abo           "1раз при увімк."
#define str_gpsupdintmenu_updintrvl     "Період оновл."

#define str_gpsposbrdcstmenu_back       "Назад"
#define str_gpsposbrdcstmenu_1m         "1 хвилина"
#define str_gpsposbrdcstmenu_90s        "90 секунд"
#define str_gpsposbrdcstmenu_5m         "5 хвилин"
#define str_gpsposbrdcstmenu_15m        "15 хвилин"
#define str_gpsposbrdcstmenu_1h         "1 година"
#define str_gpsposbrdcstmenu_2h         "2 годин"
#define str_gpsposbrdcstmenu_3h         "3 годин"
#define str_gpsposbrdcstmenu_4h         "4 годин"
#define str_gpsposbrdcstmenu_5h         "5 годин"
#define str_gpsposbrdcstmenu_6h         "6 годин"
#define str_gpsposbrdcstmenu_12h        "12 годин"
#define str_gpsposbrdcstmenu_18h        "18 годин"
#define str_gpsposbrdcstmenu_24h        "24 годин"
#define str_gpsposbrdcstmenu_36h        "36 годин"
#define str_gpsposbrdcstmenu_48h        "48 годин"
#define str_gpsposbrdcstmenu_72h        "72 годин"
#define str_gpsposbrdcstmenu_brdcstint  "Період розсил."

#define str_bluetglmenu_back            "Назад"
#define str_bluetglmenu_enabled         "Увімкнено"
#define str_bluetglmenu_disabled        "Вимкнено"
#define str_bluetglmenu_tglbluetooth    "Блютус ув/вим"
#define str_bluetglmenu_bluetooth       "Блютус"

#define str_buzzmodemenu_allenabled     "Всі увімкнено"
#define str_buzzmodemenu_alldisabled    "Всі вимкнено"
#define str_buzzmodemenu_notifications  "Сповіщення"
#define str_buzzmodemenu_systemonly     "Лише сист."
#define str_buzzmodemenu_dmsonly        "Лише приват"
#define str_buzzmodemenu_notifyonly     "Звуки сповіщ."

#define str_brightnesspicker_back       "Назад"
#define str_brightnesspicker_bcklghtp   "Підсвітка +"
#define str_brightnesspicker_bcklghtn   "Підсвітка -"
#define str_brightnesspicker_cntrstp    "Контраст +"
#define str_brightnesspicker_cntrstn    "Контраст -"
#define str_brightnesspicker_invert     "Негатив"
#define str_brightnesspicker_brightnes  "Яскравість"
#define str_brightnesspicker_low        "Назька"
#define str_brightnesspicker_med        "Середня"
#define str_brightnesspicker_high       "Висока"

#define str_switchtomui_no              "Ні"
#define str_switchtomui_yes             "Так"
#define str_switchtomui_switchtomui     "Перемкнути на MUI?"

#define str_tftcolorpicker_back         "Назад"
#define str_tftcolorpicker_default      "Стандарт"
#define str_tftcolorpicker_mshtstcgreen "Зелений Мештастик"
#define str_tftcolorpicker_yellow       "Жовтий"
#define str_tftcolorpicker_red          "Червоний"
#define str_tftcolorpicker_orange       "Помаранчевий"
#define str_tftcolorpicker_purple       "Фіолетовий"
#define str_tftcolorpicker_blue         "Синій"
#define str_tftcolorpicker_teal         "Бірюзовий"
#define str_tftcolorpicker_cyan         "Блакитний"
#define str_tftcolorpicker_ice          "Холодний"
#define str_tftcolorpicker_pink         "Рожевий"
#define str_tftcolorpicker_white        "Білий"
#define str_tftcolorpicker_gray         "Сірий"
#define str_tftcolorpicker_selectscrclr "Виберіть колір"

#define str_rebootmenu_back             "Назад"
#define str_rebootmenu_confirm          "Підтвердження"
#define str_rebootmenu_rebootdevice     "Перезапустити?"
#define str_rebootmenu_reboot           "Перезапуск"
#define str_rebootmenu_rebooting        "Перезапуск..."

#define str_shtdwnmenu_back             "Назад"
#define str_shtdwnmenu_confirm          "Підтвердження"
#define str_shtdwnmenu_shtdwndevice     "Вимкнути?"
#define str_shtdwnmenu_shutdown         "Вимкнення"

#define str_removefavmenu_back          "Назад"
#define str_removefavmenu_yes           "Так"
#define str_removefavmenu_unfvrttnode   "Розлюбити цей вузол\n"

#define str_traceroutemenu_nodetotrace  "Шлях до вузла"

#define str_testmenu_back               "Назад"
#define str_testmenu_nmbrpicker         "Вибір числа"
#define str_testmenu_showchirpy         "Показати жваве"
#define str_testmenu_hidechirpy         "Сховати жваве"
#define str_testmenu_testanounce        "Тест оголошення"
#define str_testmenu_hiddentestmenu     "Приховане меню"

#define str_numbertestpicker            "Оберіть число\n "

#define str_wifibasemenut_back          "Назад"
#define str_wifibasemenut_wifitgl       "Вай-ФАй ув/вим"
#define str_wifibasemenut_wifimenu      "Вай-ФАй меню"

#define str_wifitglmenu_back            "Назад"
#define str_wifitglmenu_wifidisabled    "Вай-ФАй вимк."
#define str_wifitglmenu_wifienabled     "Вай-ФАй увімк."
#define str_wifitglmenu_wifiactions     "Вай-ФАй"

#define str_screenoptmenu_back          "Назад"
#define str_screenoptmenu_brightness    "Яскравість"
#define str_screenoptmenu_scrcolor      "Колір дисплея"
#define str_screenoptmenu_framvsblty    "Видим. сторінок"
#define str_screenoptmenu_displyunit    "Одиниці виміру"
#define str_screenoptmenu_msgbubles     "Сплив.повідомл."
#define str_screenoptmenu_displayopt    "Нал.дисплею"

#define str_pwrmenu_back                "Назад"
#define str_pwrmenu_reboot              "Перезавантажити"
#define str_pwrmenu_shutdown            "Вимкнути"
#define str_pwrmenu_switchtoui          "Перемкнути на MUI"
#define str_pwrmenu_rebootshtdwnd       "Перезапуск/Вимк."
#define str_pwrmenu_power               "Живлення"

#define str_keyvermenupicker            "Вузол на повірку"

#define str_keyverpromptver             "Повірка ключа: \n"
#define str_keyverpromptreject          "Відмова"
#define str_keyverpromptaccept          "Прийняти"

#define str_frametglmenu_finnish        "Завершити"
#define str_frametglmenu_shownl         "Показ.сп.Вузлів"
#define str_frametglmenu_hidenl         "Схов.сп.Вузлів"
#define str_frametglmenu_shownllh       "Показ.Ост.Чутн."
#define str_frametglmenu_hidenllh       "Схов.Ост.Чутн."
#define str_frametglmenu_shownlhs       "Показ.стриб/сигн"
#define str_frametglmenu_hidenlhs       "Схов.стриб/сигн"
#define str_frametglmenu_showposlists   "Показ.сп.Позиц."
#define str_frametglmenu_hideposlists   "Схов.сп.Позиц."
#define str_frametglmenu_shownldist     "Показ.сп.Відст."
#define str_frametglmenu_hidenldist     "Схов.сп.Відст."
#define str_frametglmenu_shownlbear     "Показ.сп.Напр."
#define str_frametglmenu_hidenlbear     "Схов.сп.Напр."
#define str_frametglmenu_showpos        "Показ.Місцезнах."
#define str_frametglmenu_hidepos        "Схов.Місцезнах."
#define str_frametglmenu_showlora       "Показ.ЛОРА"
#define str_frametglmenu_hidelora       "Схов.ЛОРА"
#define str_frametglmenu_showclock      "Показ.Годинник"
#define str_frametglmenu_hideclock      "Схов.Годинник"
#define str_frametglmenu_showfav        "Показ.Улюблені"
#define str_frametglmenu_hidefav        "Схов.Улюблені"
#define str_frametglmenu_hideenvtele    "Схов.тел.Серед."
#define str_frametglmenu_showenvtele    "Показ.тел.Серед."
#define str_frametglmenu_hideaqtele     "Схов.тел.Як.Пов."
#define str_frametglmenu_showaqtele     "Показ.тел.Як.Пов."
#define str_frametglmenu_hidepower      "Схов.Живлення"
#define str_frametglmenu_showpower      "Показ.Живлення"
#define str_frametglmenu_showhideframes "Пок./Cхов.Сторінки"

#define str_dispunitmenu_back           "Назад"
#define str_dispunitmenu_metric         "Метрична"
#define str_dispunitmenu_retard         "Каліцька"
#define str_dispunitmenu_seldispunit    "Одиниці виміру"

#define str_msgbublmenu_back            "Назад"
#define str_msgbublmenu_shoebbls        "Показ.Спливаючі"
#define str_msgbublmenu_hidebbls        "Схов.Спливаючі"
#define str_msgbublmenu_msgbbls         "Сплив.повідомл."

#define str_throttlemsg                 "Забагато спроб\nСпробуй за хвилину"

// graphics/draw/DebugRenderer.cpp

#define str_dbgrndr_client              "Клієнт";
#define str_dbgrndr_app                 "Клієнт"
#define str_dbgrndr_nocon               "Нема підключень"
#define str_dbgrndr_wifi                "ВайФай"
#define str_dbgrndr_wifinc              "ВайФай не під'єднано"
#define str_dbgrndr_wificc              "ВайФай під'єднано"
#define str_dbgrndr_wifinssid           "SSID не знайдено"
#define str_dbgrndr_wifilost            "З'єдннання втрачно"
#define str_dbgrndr_wifiidle            " ... З'єдннання"
#define str_dbgrndr_wififail            "Невдале з'єдннання"
#define str_dbgrndr_wifiunknown         "Невідомо: %d"

#define str_dbgrndr_up                  "Працює: "
#define str_dbgrndr_usb                 "УПШ"
#define str_dbgrndr_chutil              "Зав.Кан.:"
#define str_dbgrndr_chutil2             "Зав.Кан. %2.0f%%"
#define str_dbgrndr_lorainfo            "ЛОРА"
#define str_dbgrndr_lora                "ЛОРА"
#define str_dbgrndr_ble                 "БТ: %s"
#define str_dbgrndr_role                "Роль: %s"
#define str_dbgrndr_freq                "Част.: %sМГц"
#define str_dbgrndr_freqs               "%sМГц (%d)"

#define str_dbgrndr_system              "Система"
#define str_dbgrndr_heap                "Купа:"

#define str_dbgrndr_conble              "%s підкл.(БТ)"
#define str_dbgrndr_conwifi             "%s підкл.(ВайФай)"
#define str_dbgrndr_conser              "%s підкл.(Посл.порт)"
#define str_dbgrndr_conint              "%s підкл.(Внутр.)"
#define str_dbgrndr_conhttp             "%s підкл.(ХТТП)"
#define str_dbgrndr_coneth              "%s підкл.(Есернет)"

// graphics/draw/MessageRenderer.cpp

#define str_drawtxtmsgframe_msgtitle    "Повідомлення"
#define str_drawtxtmsgframe_messages    "Повідомлення"
#define str_drawtxtmsgframe_dm          "(Ос.)"

#define str_drawtxtmsgframe_times       "%uс"
#define str_drawtxtmsgframe_timem       "%uхв"
#define str_drawtxtmsgframe_timeh       "%uгод"
#define str_drawtxtmsgframe_timed       "%uдн"

#define str_drawtxtmsgframe_stos        "%s до %s"

#define str_drawtxtmsgframe_alertfrom   "Оголошення від\n%s"
#define str_drawtxtmsgframe_alertrcvd   "Нове оголошення"
#define str_drawtxtmsgframe_msgfrom     "Повідомлення від\n%s"
#define str_drawtxtmsgframe_newmsg      "Нове повідомлення"
#define str_drawtxtmsgframe_nomsg       "Немає повідомлень"

#define str_drawtxtmsgframe_inns        "в #%s"
#define str_drawtxtmsgframe_inch        "в Ch%d"

// graphics/draw/NodeListRenderer.cpp

#define str_getcurmodtit_lastheard      "Нещодавні"
#define str_getcurmodtit_hopsig         "Стр/Сигнал"
#define str_getcurmodtit_hopssignal     "Стрибки / Сигнал"
#define str_getcurmodtit_hopssig        "Стрибки / Сигнал"
#define str_getcurmodtit_nodes          "Вузли"

#define str_getcurmodtit_distance       "Відстані"
#define str_getcurmodtit_bears          "Напрямки"

#define str_getcurmodtit_d              "дн"
#define str_getcurmodtit_h              "год"
#define str_getcurmodtit_m              "хв"

#define str_drawnodeinfo_2distft        "%dфт"
#define str_drawnodeinfo_2distmi        "¼мл"
#define str_drawnodeinfo_2distmi2       "%dмл"
#define str_drawnodeinfo_2distm         "%dм"
#define str_drawnodeinfo_2distkm        "1км"
#define str_drawnodeinfo_2distkm2       "%dкм"

#define str_scrollpopupoverlay          "%d-%d/%d Стор.%d/%d"

// graphics/draw/NotificationRenderer.cpp

#define str_sslscreen_msg               "Робиться SSL сертифікат"
#define str_sslscreen_wait1             "Чекай . . ."
#define str_sslscreen_wait2             "Чекай . .  "

#define str_drawnotifybox_signal        "Сигнал:"
#define str_drawnotifybox_alert         "Отримано оголошення"

#define str_drawcritical_fault          "Критична помилка #%d"
#define str_drawcritical_help           "За допомогою, відвідай \nt.me/meshtastic_ua"
#define str_drawcritical_update         "Оновлення"
#define str_drawcritical_please         "Чекай і не вимикай!"

// graphics/draw/UIRenderer.cpp

#define str_drawgps_fixed               "Зафіксовано"
#define str_drawgps_nolock              "Нема фіксац."
#define str_drawgps_nosats              "Нама супутн."
#define str_drawgps_xsats               "%u супутн."

#define str_drawgps_nogps               "Без ГНС"
#define str_drawgps_gpsoff              "ГНС вимкнена"
#define str_drawgps_gpsnotpresent       "ГНС не знайдено"
#define str_drawgps_gpsdisabled         "ГНС відключено"

#define str_drawgps_altretard           "Висота: %.0fft"
#define str_drawgps_altmeters           "Висота: %.0im"

#define str_drawgps_nogpspresent        "ГНС відсутня"
#define str_drawgps_nogpslock           "ГНС не зафікс."
#define str_drawgps_nogpsmodule         "Нема модуля ГНС"

#define str_drawgps_declat              "Шир: %f"
#define str_drawgps_declon              "Дов: %f"
#define str_drawgps_altlat              "Шир: %2i° %2i' %2u\" %1c"
#define str_drawgps_altlon              "Дов: %3i° %2i' %2u\" %1c"

#define str_drawnodeinfo_sig            "%sСиг.:%s"
#define str_drawnodeinfo_good1          "Відмінний"
#define str_drawnodeinfo_good2          "Хороший"
#define str_drawnodeinfo_good3          "Нормальний"
#define str_drawnodeinfo_fair           "Задовільний"
#define str_drawnodeinfo_bad            "Слабкий"

#define str_drawnodeinfo_heard1         " Чути:?"
#define str_drawnodeinfo_heard2         "%sЧути:%d%s тому"

#define str_drawnodeinfo_d              "дн"
#define str_drawnodeinfo_h              "год"
#define str_drawnodeinfo_m              "хв"

#define str_drawnodeinfo_sup            "%sПрацює:"
#define str_drawnodeinfo_distft         "%sВідстань:%dфт"
#define str_drawnodeinfo_distmi         "%sВідстань:¼мл"
#define str_drawnodeinfo_distmi2        "%sВідстань:%dмл"
#define str_drawnodeinfo_distm          "%sВідстань:%dм"
#define str_drawnodeinfo_distkm         "%sВідстань:1км"
#define str_drawnodeinfo_distkm2        "%sВідстань:%dкм"

#define str_drawnodeinfo_bat1           "%sАКБ:%d%% (%.2fВ)"
#define str_drawnodeinfo_bat2           "%sАКБ:%d%%"
#define str_drawnodeinfo_bat3           "%sЗарядж. (%.2fВ)"
#define str_drawnodeinfo_bat4           "%sЗарядж."
#define str_drawnodeinfo_bat5           "%sАКБ:%.2fВ"

#define str_drawdevfocused_home         "Домівка"

#define str_drawdevfocused_online       "онлайн"
#define str_drawdevfocused_uptime       "Працює: "

#define str_drawdevfocused_fixedgps     "Фікс.поз.";
#define str_drawdevfocused_nogps        "Без ГНС"
#define str_drawdevfocused_gpsoff       "ГНС вимкнена"

#define str_drawdevfocused_bat6         "%01d.%02dV"
#define str_drawdevfocused_usb          "УПШ"
#define str_drawdevfocused_chutil       "Зав.Кан."
#define str_drawdevfocused_btoff        "БТ вимк."

#define str_einkdeepsleep_sleeping      "Сплю"
#define str_einkdeepsleep_paused        "Дисплей призупинено"

#define str_drawiconscreen_tasticurl    "wikimesh.in.ua"

#define str_drawcompaslocscreen_pos     "Місцезнах."
#define str_drawcompaslocscreen_last    "Остан.: "
#define str_drawcompaslocscreen_last2   "Остан.: ?"

#define str_drawtimedelta_d             "дн"
#define str_drawtimedelta_h             "год"
#define str_drawtimedelta_m             "хв"
#define str_drawtimedelta_s             "с"

// modules/CannedMessageModule.cpp

#define str_launchwithdest_selectdest   "[Вибір отримувача]"
#define str_launchwithdest_freetext     "[ Набір тексту ]"

#define str_drawheader_to1              "До: #%s"
#define str_drawheader_to2              "До: @%s"

#define str_handlmsgselectinput_exit    "[Вихід]"
#define str_handlmsgselectinput_sendmsg "Надіслати?"

#define str_sendtext_sending            "Надсилання..."

#define str_drawdestselscr_selectdest   "Вибір отримувача"

#define str_drawframe_carleft           "%d симв."
#define str_drawframe_destshift         "Отрим.: Шифт + "

#define str_getsiggrade_good1           "відмінний"
#define str_getsiggrade_good2           "хороший"
#define str_getsiggrade_good3           "нормальний"
#define str_getsiggrade_fair            "задовільний"
#define str_getsiggrade_bad             "слабкий"
                                        
#define str_hndlreceived_msgsent        "Надіслано в\n#%s\n\nсиг. %s"
#define str_hndlreceived_dmsent         "Особисте надіслано\n@%s\n\nсиг. %s"
#define str_hndlreceived_dmrelayed      "Особисте передано\n(стан невідомо)\n%s\n\nсиг.%s"
#define str_hndlreceived_msgfailed      "Невдача в\n#%s"
#define str_hndlreceived_dmfailed       "Невдача в\n@%s"

#define str_defaultcanmsg_msg           "Так|Ні|Ясно|Пінг|Понг"

// modules/DetectionSensorModule.cpp

#define str_senddetectmsg_detected      "%s зафіксовано"
#define str_senddetectmsg_state         "%s стан: %i"

// platform/nrf52/NRF52Bluetooth.cpp
// nimbe/NimbleBluetooth.cpp

#define str_onpairpass_bluetooth        "Блютус"
#define str_onpairpass_entercode        "Введіть цей код"

// motion/MotionSensor.cpp

#define str_framecalibration_cal        "Калібр."
#define str_framecalibration_8          "Форма-8"
#define str_framecalibration_rotateax   "Крутіть усюди"
#define str_framecalibration_awayfrom   "Подалі від металу"
#define str_framecalibration_compcalib  "Калібрація компаса"
#define str_framecalibration_movein8    "Крутіть у формі 8-ки"
#define str_framecalibration_rotateall  "Крутіть у всі напрямки"
#define str_framecalibration_keetfrom   "Подалі від металу"
#define str_framecalibration_compascal  "Калібр. компас"
#define str_framecalibration_moveinfig  "Крутіть у 8"
#define str_framecalibration_rotatealax "Крутіть усюди"
#define str_framecalibration_frommetal  "Подалі від металу"

#define str_framecalibration_000leftft  "000с лишилось"
#define str_framecalibration_usleft     "%luс лишилось"
#define str_framecalibration_us         "%luс"

// modules/WaypointModule.cpp

#define str_waypointdrawframe_wp        "Пункт"

// modules/TraceRouteModule.cpp

#define str_alterRecievedpb_db          "дБ)"
#define str_printroute_db1              "0x%x (%.2fдБ) --> "
#define str_printroute_db2              "0x%x (?дБ) --> "
#define str_printroute_db3              "0x%x (%.2fдБ)"
#define str_printroute_db4              "0x%x (?дБ)"
#define str_printroute_db5              "(%.2fдБ) 0x%x <-- "
#define str_printroute_db6              "(?дБ) 0x%x <-- "

#define str_starttrace_invalid          "Непридатний вузол"
#define str_starttrace_cantself         "Себе не можна"

#define str_tracecolldwn_wait           "Чекай "
#define str_tracecolldwn_s              "с"
#define str_tracecolldwn_tracing        "Відслідковуємо \n"
#define str_tracecolldwn_failed         "Навдача надсилання "
#define str_tracecolldwn_unavailable    "Сервіс не доступний"
#define str_tracecolldwn_noresponse     "Немає відповіді"
#define str_tracecolldwn_result         "Результат "

// modules/telemetry/PowerTelemetry.cpp

#define str_powerteledraw_pwrtele       "Телеметрія живл."
#define str_powerteledraw_pwr           "Живлення"
#define str_powerteledraw_nomeasure     "Нама виміру"
#define str_powerteledraw_measureerr    "Помилка виміру"
#define str_powerteledraw_powfrom       "Живл.від: %s (%uс)"
#define str_powerteledraw_values        "%s: %.2fВ %.0fмА"

// modules/telemetry/HealthTelemetry.cpp

#define str_healthteledraw_health       "Здоров'я"
#define str_healthteledraw_nomeasure    "Нама виміру"
#define str_healthteledraw_measureerr   "Помилка виміру"
#define str_healthteledraw_healthfrom   "Здоров'я від: %s(%dс)"
#define str_healthteledraw_temp         "Темп.: %s"
#define str_healthteledraw_heart        "Серц.Ритм: %u у/хв"
#define str_healthteledraw_spo2         "Нас.Кисн.: %u %%"

// modules/telemetry/EnvironmentTelemetry.cpp

#define str_envdrawframe_environment    "Середовище"
#define str_envdrawframe_env            "Сер."
#define str_envdrawframe_notele         "Нема телеметр."
#define str_envdrawframe_h              "год"
#define str_envdrawframe_m              "хв"
#define str_envdrawframe_s              "с";
#define str_envdrawframe_temp           "темп.: "
#define str_envdrawframe_hum            "вол.: "
#define str_envdrawframe_prss           "тимк: "
#define str_envdrawframe_hpa            " гПа"
#define str_envdrawframe_iaq            "Як.Поітр.: "

#define str_envdrawframe_excellenet     " (Відмінна)"
#define str_envdrawframe_good           " (Добра)"
#define str_envdrawframe_moderate       " (Задовільна)"
#define str_envdrawframe_poor           " (Погана)"
#define str_envdrawframe_unhealthy      " (Шкідлива)"
#define str_envdrawframe_unhiaq         "Шкідлива як.пов."
#define str_envdrawframe_veryunhealthy  " (Дуже шкідлива)"
#define str_envdrawframe_veryunhiaq     "Дуже шкідлива як.пов."
#define str_envdrawframe_hazard         " (Небезпечна)"
#define str_envdrawframe_hazardiaq      "Небезпечна як.пов."

#define str_envdrawframe_v              "В / "
#define str_envdrawframe_ma             "мА"
#define str_envdrawframe_light          "Світло: "
#define str_envdrawframe_lx             "люкс"
#define str_envdrawframe_white          "Біле: "
#define str_envdrawframe_weight         "Масса: "
#define str_envdrawframe_kg             "кг"
#define str_envdrawframe_level          "Рівень: "
#define str_envdrawframe_mm             "мм"
#define str_envdrawframe_rad            "Випром.: "
#define str_envdrawframe_urh            " мкР/год"

// modules/SystemCommandsModule.cpp

#define str_syscommodule_notifydisabled "Сповіщення\nвимкнено"
#define str_syscommodule_notifyenabled  "Сповіщення\nувімкнено"
#define str_syscommodule_btoffreboot    "Блютус вимк.\nПерезапуск"
#define str_syscommodule_btonrebbot     "Блютус увім.\nПерезапуск"
#define str_syscommodule_btoff          "Блютус вимк."
#define str_syscommodule_rebbot         "Перезапуск..."
#define str_syscommodule_gpson          "ГНС увімкнена"
#define str_syscommodule_gpsoff         "ГНС вимкнена"
#define str_syscommodule_possent        "Координати\nнадіслано"
#define str_syscommodule_infosent       "Інфо вузла\nнадіслано"

// modules/ReplyModule.cpp

#define str_replymodule_recv            "Повідомлення\nотримано"

// graphics/TimeFormatters.cpp

#define str_timeagostr_sa               "%u секунд тому"
#define str_timeagostr_ma               "%u хвилин тому"
#define str_timeagostr_ls               "Востаннє: %02u:%02u"
#define str_timeagostr_sy               "Був вчора"
#define str_timeagostr_da               "%li днів тому"
#define str_timeagostr_ha               "%u годин тому"
#define str_timeagostr_un               "невідомо коли"

#define str_uptimestr_dh                "%s%uдн %uгод"
#define str_uptimestr_hm                "%s%uгод %uхв"
#define str_uptimestr_m                 "%s%uхв"
#define str_uptimestr_ms                "%s%uхв %uс"
#define str_uptimestr_s                 "%s%uс"

// graphics/Screen.cpp

#define str_showtxtinput_txinput        "Ввід тексту"
#define str_runonce_rebooting           "Перезапуск..."
#define str_hndltxtmsg_msg              "Повідомлення"
#define str_hndltxtmsg_alertfrom        "Оголошення від\n%s"
#define str_hndltxtmsg_alert            "Нове оголошення"
#define str_hndltxtmsg_msgfrom          "Повідомлення від\n%s"
#define str_hndltxtmsg_newmsg           "Нове\nповідомлення"
