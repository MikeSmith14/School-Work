//
//  AreaMapViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 2/14/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit

class AreaMapViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */
    @IBAction func GoogleMapButtonPressed(_ sender: Any) {
        UIApplication.shared.open(URL(string: "https://www.google.com/maps/dir/''/loma+linda+university+medical+center+google+maps/@34.0465367,-117.3712998,11.38z/data=!4m8!4m7!1m0!1m5!1m1!1s0x80dcab862f872d17:0x562258fb1aebc10f!2m2!1d-117.2641184!2d34.0498473" )! as URL, options: [:], completionHandler: nil)
    }
    
}
