import java.util.Scanner;

public class Aplication {
    public static void main(String[] args) {
        int command;
        Scanner s = new Scanner(System.in);

        while (true)
        {
            printMeniu();

            try {
                command = Integer.parseInt(s.nextLine());
                switch (command)
                {
                    case 0:
                        return;
                    case 1:
                        afisareSir(citireSir());
                        break;
                    case 2:
                        afisareSubsecventaMaxima();
                        break;
                    default:
                        System.out.println("Comanda invalida");
                }
            } catch (Exception e)
            {
                System.out.println("Introdu numere");
            }
        }
    }

    private static void afisareSubsecventaMaxima() {
        /*Sir sir = new Sir(13);
        sir.addElement(10);
        sir.addElement(2);
        sir.addElement(3);
        sir.addElement(7);
        sir.addElement(2);
        sir.addElement(2);
        sir.addElement(2);
        sir.addElement(2);
        sir.addElement(7);
        sir.addElement(2);
        sir.addElement(2);
        sir.addElement(2);
        sir.addElement(11);
        afisareSir(sir.SecvMax());*/
        afisareSir(citireSir().SecvMax());
    }

    private static void afisareSir(Sir sir) {
        System.out.println("Sir: ");
        for(int i = 0; i < sir.getLungime(); i++)
            System.out.print(sir.getElement(i) + " ");
        System.out.println();
    }

    private static Sir citireSir() {
        try{
            Scanner s = new Scanner(System.in);
            System.out.println("Introdu lungimea sirului");
            int lungime = Integer.parseInt(s.nextLine());

            int element;
            Sir rezultat = new Sir(lungime);

            for (int i = 0; i < lungime; i++)
            {
                System.out.print("sir[" + i + "] = ");
                element = Integer.parseInt(s.nextLine());
                rezultat.addElement(element);
            }

            return rezultat;
        } catch (Exception e)
        {
            System.out.println("Date introduse gresit");
            return new Sir();
        }
    }

    private static void printMeniu() {
        System.out.println("0. Exit");
        System.out.println("1. Afisaza un sir citit");
        System.out.println("2. Subsecventa maxima");
        System.out.println("Introduceti comanda:");
    }
}
