#pragma once
#include <vector>

void commInit();
void sendSessionState(int avgRemainingTime, int curScore);
void sendSessionResult(int avgResponseTime);
void sendMessage(const String& message);
void askForNewSession();