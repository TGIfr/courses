
import org.jbehave.core.annotations.Given;
import org.jbehave.core.annotations.Then;
import org.jbehave.core.annotations.When;

import static org.junit.Assert.assertEquals;

public class Steps {


    MxLangEnvironment env;
    Object res;
    private Exception exception;

    // Given

    @Given("an empty env")
    public void newEnvironment() {
        env = new MxLangEnvironment();
    }



    // When

    @When("I enter string $string")
    public void iEvaluateString(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }


    // When



    @When("I get not saved var $string")
    public void iEvaluateNotSavedVar(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }

    @When("I enter expression with no variables without saving $string")
    public void iEvaluateExpNoSave(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }

    @When("I enter matrix $string")
    public void iEvaluateMatrix(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }

    @When("I save variable $string")
    public void iEvaluateVar(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }

    @When("I save variable A $string")
    public void iEvaluateVarA(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }

    @When("I save variable B $string")
    public void iEvaluateVarB(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }

    @When("I enter expression with saved variables A and B with no saving $string")
    public void iEvaluateExprFromSaved(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }

    @When("I enter expression with saved variables A and B and save it in C $string")
    public void iEvaluateExprFromSavedAndSave(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }

    @When("I get saved variable $string")
    public void iEvaluateGetVar(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }

    @When("I get saved variable C $string")
    public void iEvaluateGetVarC(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }

    @When("I enter invalid operation $string")
    public void iEvaluateInvalidOperation(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }

    @When("I enter not available operation $string")
    public void iEvaluateMatrixMult(String string) {
        try{
            res = env.exec(string);
        } catch (Exception e){
            exception = e;
        }
    }



    // Then

    @Then("I should get result $value")
    public void iShouldGetResult(String value) {
        assertEquals(value, res.toString());
    }

    @Then("I should get output $value")
    public void iShouldGetOutput(String value) {
        assertEquals(value, res.toString());
    }

    @Then("I should get err $value")
    public void iShouldGetErr(String value) {
        assertEquals(value, res.toString());
    }

    @Then("I should get saved variable $value")
    public void iShouldGetVar(String value) {
        assertEquals(value, res.toString());
    }

    @Then("saved variables numbers should be $value")
    public void savedVarNum(String value) {
        assertEquals(value, Integer.toString(env.savedVariablesSize()));
    }

    @Then("I should get an error message $message")
    public void iShouldGetErrorMessage(String message) {
        assertEquals(message, exception.getMessage());
    }


}
