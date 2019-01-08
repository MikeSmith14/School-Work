//
//  Cafateria MenuViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 2/14/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit

class Cafateria_MenuViewController: UIViewController {

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

    @IBAction func UniversityHospitalButtonPressed(_ sender: Any) {
        UIApplication.shared.open(URL(string: "https://myllu.llu.edu/cafeterias/?cafeteriaId=5#dailyMenu" )! as URL, options: [:], completionHandler: nil)
    }
    
    @IBAction func ChildrensHospitalButtonPressed(_ sender: Any) {
        UIApplication.shared.open(URL(string: "https://myllu.llu.edu/cafeterias/?menuDate=2018-01-24&cafeteriaId=6#dailyMenu" )! as URL, options: [:], completionHandler: nil)
    }
    
}
