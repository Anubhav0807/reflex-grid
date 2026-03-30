#pragma once

void httpInit();
String httpGet(const String& path);
String httpPost(const String& path, const String& body);