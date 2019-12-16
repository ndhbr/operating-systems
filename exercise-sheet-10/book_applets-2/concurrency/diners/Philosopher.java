package concurrency.diners;

import java.awt.*;

class Philosopher extends Thread {
  private int identity;
  private PhilCanvas view;
  private Diners controller;
  private Fork left;
  private Fork right;

  Philosopher(Diners ctr, int id, Fork l, Fork r) {
    controller = ctr; view = ctr.display;
    identity = id; left = l; right = r;
  }

  public void run() {
    try {
      while (true) {
        //thinking
        view.setPhil(identity,view.THINKING);
        sleep(controller.sleepTime());
        synchronized (left) {
            //hungry
            view.setPhil(identity,view.HUNGRY);
            while (left.isTaken()) left.wait();
            right.get();
            //gotright chopstick
            view.setPhil(identity,view.GOTRIGHT);
            sleep(500);
            left.get();
        }
        //eating
        synchronized (left) {
            view.setPhil(identity,view.EATING);
            sleep(controller.eatTime());
            right.put();
            left.put();
            left.notify();
        }
      }
    } catch (java.lang.InterruptedException e) {}
  }
}
