#include<graphics.h>
#include<iostream>
int main()
{
int height = GetSystemMetrics (SM_CYSCREEN); int width= GetSystemMetrics (SM_CXSCREEN);
initwindow (width, height);
int x=100, y=100;
while (1)
{
cleardevice();
circle (x, y, 50);
if (GetAsyncKeyState (VK_RIGHT))
x += 10;
else if (GetAsyncKeyState (VK_LEFT))
x-= 10;
else if (GetAsyncKeyState (VK_UP))
y -= 10;
else if (GetAsyncKeyState (VK_DOWN))
y += 10;
if (GetAsyncKeyState (VK_RETURN))
break;
delay(10);
}
closegraph ();
}

