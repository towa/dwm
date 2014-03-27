#define NUMCOLORS         6             // need at least 3
static const char colors[NUMCOLORS][ColLast][8] = {
   // border   foreground  background
   { "#2d2823", "#2d2823", "#d7d8ae" },  // 0 = normal
   { "#154d4e", "#154d4e", "#d7d8ae" },  // 1 = selected
   { "#c92d2b", "#c92d2b", "#d7d8ae" },  // 2 = urgent/warning
   { "#c92d2b", "#d7d8ae", "#c92d2b" },  // 3 = error
   { "#789c99", "#789c99", "#d7d8ae" },  // 4 = Normales Symbol 
   { "#c92d2b", "#c92d2b", "#d7d8ae" },  // 5 = Symbol, welches Aufmerksamkeit verlangt 
   // add more here
};
