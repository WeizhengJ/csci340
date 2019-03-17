//Heap  Sort

void heapsort(int a[], int n)
{
int k;
construct(a,0);
for(k = 1; k <= n, k++)
	insert(a[k]);
for(k=n; k >= 1; k--)
	a[k]=remove();
}

