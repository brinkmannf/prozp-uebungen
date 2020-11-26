#ifndef _MAINFILE_H_
#define _MAINFILE_H_

/* Prototypen der benoetigten Funktionen */

struct bruch_s {
    int zaehler;
    int nenner;
};

struct bruch_s sum(struct bruch_s *bruch1, struct bruch_s *bruch2);

struct bruch_s subtract(struct bruch_s *bruch1, struct bruch_s *bruch2);

struct bruch_s multiply(struct bruch_s *bruch1, struct bruch_s *bruch2);

struct bruch_s divide(struct bruch_s *bruch1, struct bruch_s *bruch2);

void berechnung(struct bruch_s *bruchEins, struct bruch_s *bruchZwei);

void readInput(struct bruch_s *bruchEins, struct bruch_s *bruchZwei);

#endif
