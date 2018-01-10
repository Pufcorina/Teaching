public class Sir {
    private int lungime;
    private int S[];

    public Sir()
    {
        lungime = 0;
        S = new int[0];
    }

    public Sir(int lungime)
    {
        this.lungime = 0;
        S = new int[lungime];
    }

    public int getLungime() {
        return lungime;
    }

    public int getElement(int index)
    {
        return S[index];
    }

    public void addElement(int element)
    {
        S[lungime] = element;
        lungime++;
    }

    private void reset()
    {
        lungime = 0;
    }

    public Sir SecvMax()
    {
        Sir maxim = new Sir(lungime);
        Sir curent = new Sir(lungime);

        for (int pozitie = 0; pozitie < lungime; pozitie++)
        {
            if(S[pozitie] % 2 == 0)
               curent.addElement(S[pozitie]);
            else
            {
                if(maxim.getLungime() < curent.getLungime())
                    maxim = curent.copiere();
                curent.reset();
            }
        }

        return maxim;
    }

    private Sir copiere() {
        Sir rezultat = new Sir(lungime);

        for(int i = 0; i < lungime; i++)
            rezultat.addElement(S[i]);

        return rezultat;
    }
}
