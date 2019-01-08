//
//  WebLinksViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 2/14/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit

class WebLinksViewController: UIViewController {

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

    @IBAction func AmericanHeartAssociationButtonPressed(_ sender: Any) {
        UIApplication.shared.open(URL(string: "http://www.heart.org/HEARTORG/Conditions/CongenitalHeartDefects/Congenital-Heart-Defects_UCM_001090_SubHomePage.jsp" )! as URL, options: [:], completionHandler: nil)
    }
    
    @IBAction func LomaLindaUniversityMedicalCenterButtonPressed(_ sender: Any) {
        UIApplication.shared.open(URL(string: "https://medical-center.lomalindahealth.org" )! as URL, options: [:], completionHandler: nil)
    }
}
