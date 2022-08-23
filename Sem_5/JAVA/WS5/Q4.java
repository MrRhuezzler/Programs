interface Instrument {
    void play();
    String what();
    void adjust();
}

class WindInstrument implements Instrument {
    public void play() {
        System.out.println("Wind Instrument");
    }
    public String what() {
        return "Wind Instrument";
    }
    public void adjust() {
        System.out.println("Adjust Wind Instrument");
    }
}

class StringInstrument implements Instrument {
    public void play() {
        System.out.println("String Instrument");
    }
    public String what() {
        return "String Instrument";
    }
    public void adjust() {
        System.out.println("Adjust String Instrument");
    }
}

class PercussionInstrument implements Instrument {
    public void play() {
        System.out.println("Percussion Instrument");
    }
    public String what() {
        return "Percussion Instrument";
    }
    public void adjust() {
        System.out.println("Adjust Percussion Instrument");
    }
}

class WoodWindInstrument extends WindInstrument {
    @Override
    public void play() {
        System.out.println("Wood Wind Instrument");
    }

    @Override
    public String what() {
        return "Wood Wind Instrument";
    }

    @Override
    public void adjust() {
        System.out.println("Adjust Wood Wind Instrument");
    }
}

class BrassInstrument extends WindInstrument {
    @Override
    public void play() {
        System.out.println("Brass Instrument");
    }

    @Override
    public String what() {
        return "Brass Instrument";
    }
    @Override
    public void adjust() {
        System.out.println("Adjust Brass Instrument");
    }
}

public class Q4 {
    
}
