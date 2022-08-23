abstract class Question {
    private String myText;

    Question(String text) {
        myText = text;
    }

    public String getText() {
        return myText;
    }

    abstract public String getQuestion();

    abstract public String getAnswer();

    abstract public boolean checkAnswer(String answer);
}

class ShortAnswerQuestion extends Question {
    private String myAnswer;

    ShortAnswerQuestion(String text, String answer) {
        super(text);
        myAnswer = answer;
    }

    public String getQuestion() {
        return getText();
    }

    public String getAnswer() {
        return myAnswer;
    }

    public boolean checkAnswer(String answer) {
        return answer.equals(myAnswer);
    }
}

class FillInBlankQuestion extends Question {
    private String myAnswer;

    FillInBlankQuestion(String text, String answer) {
        super(text);
        myAnswer = answer;
    }

    public String getQuestion() {
        return getText();
    }

    public String getAnswer() {
        return myAnswer;
    }

    public boolean checkAnswer(String answer) {
        return answer.equals(myAnswer);
    }
}

class TrueOrFalseQuestion extends Question {
    private boolean myAnswer;
    TrueOrFalseQuestion(String text, boolean answer) {
        super(text);
        myAnswer = answer;
    }
    public String getQuestion() {
        return getText();
    }
    public String getAnswer() {
        return myAnswer ? "true" : "false";
    }
    public boolean checkAnswer(String answer) {
        return myAnswer == Boolean.parseBoolean(answer);
    }
}

public class Q1 {
    public static void main(String[] args) {
        System.out.println("Hello World");
    }

}
