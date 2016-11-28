<?php
    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "GET"){
        
        render("deposit_form.php",["title" => "Deposit"]);
    }
    else if($_SERVER["REQUEST_METHOD"] == "POST"){
        
        if(empty($_POST["money_value"]) || empty($_POST["password"])){
            error("Deposit Value and/or Password is empty!", "deposit.php");
        }
        else if($_POST["money_value"] <= 0){
            error("Deposit error!", "deposit.php");
        }
        $rows = CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        if (count($rows) == 1)
        {
            // first (and only) row
            $row = $rows[0];
            
         if((password_verify($_POST["password"], $row["hash"])) == false){
             error("Wrong password!", "deposit.php");
            
        }
        else{
            $cashUpdate = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["money_value"], $_SESSION["id"]);
             $history = CS50::query("INSERT INTO history(user_id, action, date, price) VALUES (?,'DEPOSIT', NOW(), ?)", 
      $_SESSION["id"], $_POST["money_value"]);
            if(!(empty($cashUpdate))){
                redirect("index.php");
            }
            else{
                error("Oops! Something went wrong! :/", "deposit.php");
            }
        }
    }
}


?>