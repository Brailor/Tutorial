<?php
    
    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "GET"){
        
     
        $rows = CS50::query("SELECT action, date, price, shares, symbol FROM history WHERE user_id = ?", $_SESSION["id"]);
        
        $tables = [];
        
        foreach($rows as $row){
            
            $stockName = lookup($row["symbol"]);
            
            $tables [] = [
            "action" => $row["action"],
            "date" => $row["date"],
            "price" => $row["price"],
            "shares" => $row["shares"],
            "symbol" => $row["symbol"],
            "name" => $stockName["name"]
            ];
            
        }
        
        render("history_form.php", ["tables" => $tables, "title" => "History"]);
        
    }


?>