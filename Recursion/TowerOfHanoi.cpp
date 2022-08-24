
void towerOfHanoi1(int n, char source,
 char aux, char dest) {
	 vector<string> movement;
  if (n == 0) {
    return;
  }
  
  towerOfHanoi1(n - 1, source, dest, aux);
  cout << n << " " << source <<
 " " << dest << endl;
  towerOfHanoi1(n - 1, aux, source, dest);
}