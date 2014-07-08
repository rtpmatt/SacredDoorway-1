#include <Arduino.h>

/*
 * Pulled from the Arduino Cookbook
 * #TODO Implement single or range of LED fades
 */

class rgb_color {
  private:
    int my_r;
    int my_g;
    int my_b;
  public:
    rgb_color (int red, int green, int blue)
      :
        my_r(red),
        my_g(green),
        my_b(blue)
    {
    }

    int r() const {return my_r;}
    int b() const {return my_b;}
    int g() const {return my_g;}
};

/*instances of fader can fade between two colors*/
class fader {

  private:
    int r_pin;
    int g_pin;
    int b_pin;

  public:
    /* construct the fader for the pins to manipulate.
     * make sure these are pins that support Pulse
     * width modulation (PWM), these are the digital pins
     * denoted with a tilde(~) common are ~3, ~5, ~6, ~9, ~10 
     * and ~11 but check this on your type of arduino. 
     */ 
    fader( int red_pin, int green_pin, int blue_pin)
      :
        r_pin(red_pin),
        g_pin(green_pin),
        b_pin(blue_pin)
    {
    }

    /*fade from rgb_in to rgb_out*/
    void fade( const rgb_color& in,
               const rgb_color& out,
               unsigned n_steps = 256,  //default take 256 steps
               unsigned time    = 10)   //wait 10 ms per step
    {
      int red_diff   = out.r() - in.r();
      int green_diff = out.g() - in.g();
      int blue_diff  = out.b() - in.b();
      for ( unsigned i = 0; i < n_steps; ++i){
        /* output is the color that is actually written to the pins
         * and output nicely fades from in to out.
         */
        rgb_color output ( in.r() + i * red_diff / n_steps,
                           in.g() + i * green_diff / n_steps,
                           in.b() + i * blue_diff/ n_steps);
        /*put the analog pins to the proper output.*/
        //analogWrite( r_pin, output.r() );
        //analogWrite( g_pin, output.g() );
        //analogWrite( b_pin, output.b() );
        delay(time);
      }
    }

};