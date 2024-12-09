// $(document).ready(function(){
// $("card_11").clilck(function(){
//     $("div").animate({
//         left:'250px'
//     })
// });
// })
$(document).ready(function(){
    $("#mes_button").click(function(){
      $("#show").hide();
    });
    $("#sec_button").click(function(){
      $("#show").show();
    });
  });
  $(document).ready(function(){
    $("#show").click(function(){
      $(this).hide();
    });
  });
  $(document).ready(function(){
    $("#hide").click(function(){
      $(this).hide();
    });
  });
  $(document).ready(function(){
    $("#sec_button").click(function(){
      $("#slide").slideToggle("slow");
    });
  });
function dataload(){
  var data= new XMLHttpRequest();
  data.onreadystatechange=function(){
    alert(this.readystate);
    if(this.readyState==4){
document.getElementById("demo").innerHTML=this.responseText;
    }
  }
  data.open("Get","regestationform.html",true)
  data.send();
}
  

