#define NUMCOLORS         6             // need at least 3
static const char colors[NUMCOLORS][ColLast][8] = {
   // border   foreground  background
   { "#93a1a1", "#93a1a1", "#002b36" },  // 0 = normal
   { "#cb4b16", "#cb4b16", "#002b36" },  // 1 = selected
   { "#dc322f", "#dc322f", "#002b36" },  // 2 = urgent/warning
   { "#dc322f", "#dc322f", "#002b36" },  // 3 = error
   { "#2aa198", "#2aa198", "#002b36" },  // 4 = Normales Symbol 
   { "#d33682", "#d33682", "#002b36" },  // 5 = Symbol, welches Aufmerksamkeit verlangt 
   // add more here
};
