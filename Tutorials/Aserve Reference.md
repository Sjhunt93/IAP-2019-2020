# Aserve 2.0 reference guide
*updated to version 2.0.65

This guide describes details each of the functions within aserve and examples of these.


## aserveOscillator
```cpp
    void aserveOscillator (int channel, float frequency, float amplitude, int wavetype);
```

Controls aserve's inbuilt oscillators.

- oscillatorNumber: selects the oscillator: 0 - 23
- frequency: sets the selected oscillator's frequency: 0.0Hz - 20000.0Hz
- amplitude: sets the selected oscillator's amplitude: 0.0 to 1.0
- wave: sets the selected oscillator's waveform: 0 = sine, 1 = pulse, 2 = saw, 3 = reverse saw, 4 = triangle, 5 = noise


