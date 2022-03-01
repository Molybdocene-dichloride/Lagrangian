
const LagrangianRegistries = WRAP_NATIVE("LagrangianRegistries");
const CreativeTabs = WRAP_NATIVE("CreativeTabs");
const Category = WRAP_NATIVE("Category");

let rji = new UI.Window({
  location: {
    x: 110,
    y: 20,
    width: 25,
    height: 25
  },
  elements: {
    "prev": {
      type: "button", x: 0, y: 0, bitmap: "prev", bitmap2: "prev_press", scale: 60,
      clicker: {
        onClick: function () {
          Logger.Log('tlooop');
          CreativeTabs.prevPage({});
        }
      }
    },
  }
});

let ri = new UI.Window({
  location: {
    x: 370,
    y: 20,
    width: 25,
    height: 25
  },
  elements: {
    "post": {
      type: "button", x: 0, y: 0, bitmap: "post", bitmap2: "post_press", scale: 60,
      clicker: {
        onClick: function () {
          Logger.Log('vlooop');
          CreativeTabs.nextPage({});
        }
      }
    },
  }
});

let rj = new UI.Window({
  location: {
    x: 480,
    y: 20,
    width: 85,
    height: 25
  },
  elements: {
    "info": {
      type: "text", x: 0, y: 0, text: "0 / 0", font: {size: 220, color: android.graphics.Color.WHITE}
    }
  }
});
rj.getBackgroundProvider().setBackgroundColor("0x00000000");

rji.setAsGameOverlay(true);
ri.setAsGameOverlay(true);
rj.setAsGameOverlay(true);

Callback.addCallback("PostLoaded", function () {
  let r = LagrangianRegistries.registerCategory({id: "TEST", isCreative: 1});
  
  Logger.Log(r);
  Category.addItems({_pointer: r, item_id: 261, item_data: 0, item_count: 1});
});

Callback.addCallback("NativeGuiChanged", function(screen, last_screen) {
  Logger.Log(screen);
  if(screen == "inventory_screen") {
    rji.open();
    rj.open();
    ri.open();
  } else if(last_screen == "inventory_screen") {
    rji.close();
    rj.close();
    ri.close();
  }
  CreativeTabs.invalidate();
});

Callback.addCallback("CreativePageChanged", function(page, last_page) {
  rj.getElements().get("info").setBinding("text", page + " / " + CreativeTabs.getPageCount());
});