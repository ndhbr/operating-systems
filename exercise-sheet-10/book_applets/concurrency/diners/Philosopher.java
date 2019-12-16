package concurrency.diners;

import java.awt.*;

class Philosopher extends Thread {

  static int count;
  private int identity;
  private PhilCanvas view;
  private Diners controller;
  private Fork left;
  private Fork right;

  static { count = 0; }

  Philosopher(Diners ctr, Fork l, Fork r) {
    controller = ctr; view = ctr.display;
    identity = count++; left = l; right = r;
  }

  public void run() {
    try {
      while (true) {
        //thinking
        view.setPhil(identity,view.THINKING);
        sleep(controller.sleepTime());
        //hungry
        view.setPhil(identity,view.HUNGRY);
        right.get();
        //gotright chopstick
        view.setPhil(identity,view.GOTRIGHT);
        sleep(500);
        left.get();
        //eating
        view.setPhil(identity,view.EATING);
        sleep(controller.eatTime());
        right.put();
        left.put();
      }
    } catch (java.lang.InterruptedException e) {}
  }
}
