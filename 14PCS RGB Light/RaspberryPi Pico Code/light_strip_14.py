import array, time
import random
from machine import Pin
import rp2

# Configure the number of WS2812 LEDs.
NUM_LEDS = 14
brightness = 0.2

RED = (255, 0, 0)
YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
CYAN = (0, 255, 255)
BLUE = (0, 0, 255)
PURPLE = (180, 0, 255)
WHITE = (255, 255, 255)


@rp2.asm_pio(sideset_init=rp2.PIO.OUT_LOW, out_shiftdir=rp2.PIO.SHIFT_LEFT, autopull=True, pull_thresh=24)
def ws2812():
    T1 = 2
    T2 = 5
    T3 = 3
    wrap_target()
    label("bitloop")
    out(x, 1)               .side(0)    [T3 - 1]
    jmp(not_x, "do_zero")   .side(1)    [T1 - 1]
    jmp("bitloop")          .side(1)    [T2 - 1]
    label("do_zero")
    nop()                   .side(0)    [T2 - 1]
    wrap()


# Create the StateMachine with the ws2812 program, outputting on Pin(22).
sm = rp2.StateMachine(0, ws2812, freq=8_000_000, sideset_base=Pin(22))

# Start the StateMachine, it will wait for data on its FIFO.
sm.active(1)

# Display a pattern on the LEDs via an array of LED RGB values.
ar = array.array("I", [0 for _ in range(NUM_LEDS)])

def pixels_show():
    dimmer_ar = array.array("I", [0 for _ in range(NUM_LEDS)])
    for i,c in enumerate(ar):
        r = int(((c >> 8) & 0xFF) * brightness)
        g = int(((c >> 16) & 0xFF) * brightness)
        b = int((c & 0xFF) * brightness)
        dimmer_ar[i] = (g<<16) + (r<<8) + b
    sm.put(dimmer_ar, 8)
    time.sleep_ms(1)

def pixels_set(i, color):
    ar[i] = (color[1]<<16) + (color[0]<<8) + color[2]

def color_chase(color, wait):
    for i in range(NUM_LEDS):
        pixels_set(i, color)
        time.sleep(wait)
        pixels_show()
     
def pixels_clean():
    color_chase((0,0,0), 0.001)
    

#---------------------------------------------------------------->>>>

#Turn on 1 light
def one_light():
    pixels_set(0,RED)
    pixels_show()
    
#Turn on all light
def all_light():
    color_chase(YELLOW,0.01)
    pixels_show()

#Color switch
def color_light():
    color = (0,0,0)
    for i in range(NUM_LEDS):
        r = random.randint(0,255)
        g = random.randint(0,255)
        b = random.randint(0,255)
        color = (r,g,b)
        pixels_set(i, color)
        time.sleep(0.5)
        pixels_show()

# water light
def water_light():
    while True:
        color_chase(YELLOW,0.1)
        pixels_clean()
        time.sleep(0.2)
        
        
#Breathing
def breathing(color):
    global brightness
    automatic = 1
    conut =0
    color_chase(color, 0.01)
    while True:
        conut = conut + automatic
        brightness = conut/255
        pixels_show()
        if conut <= 0 or conut >= 255:
            automatic = -automatic
    time.sleep_ms(50)
    


try:
    #one_light()
    
    #all_light()
    
    #color_light()
    
    #water_light()
    
    breathing(CYAN)
except Exception as err:
    pass

