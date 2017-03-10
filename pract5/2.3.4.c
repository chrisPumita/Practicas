Stack * Stack_Ctor (int max)
{
Stack * newStack = (Stack *) malloc (sizeof (Stack));
// crea a un nuevo objeto Stack en el heap
assert (newStack);
newStack->stack = (double *) malloc (max * sizeof (double));
// crea a un nuevo contenedor (el arreglo) de double's en el heap
assert (newStack->stack);
newStack->top = 0;
newStack->max = max;
return newStack;
}
void Stack_Dtor (Stack * this)
{
assert (this);
free (this->stack);
// devuelve la memoria del arreglo
free (this);
// devuelve la memoria del objeto
}
// … igual que antes
#define MAX_TAM 5
int main()
{
Stack * miPila = Stack_Ctor (MAX_TAM);
while (Stack_IsFull (miPila) == FALSE) {
double valor = 0.0;
printf ("Nuevo valor: ");
scanf ("%lf", &valor);
Stack_Push (miPila, valor);
}
while (Stack_IsEmpty (miPila) == FALSE) {
printf ("<%f>\n", Stack_Pop (miPila));
}
Stack_Dtor (miPila);
// en esta versión ¡no olvidar llamar al destructor!
return 0;
}
