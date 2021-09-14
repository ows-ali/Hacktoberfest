import pyautogui as g
import time
g.press('win')
time.sleep(1)
g.typewrite('note', interval=0.25)
time.sleep(1)
g.press('enter')
time.sleep(1)
g.typewrite('Hello folks!!\nHow are you doing?', interval=0.25)
