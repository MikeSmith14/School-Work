//
//  ShortBreakViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 2/14/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit
import Contacts

public var deletedNumbers = [String]()
public var orderItems = [String]()

class ShortBreakViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    
    @IBOutlet weak var editButton: UIBarButtonItem!
    @IBOutlet weak var contactTableView: UITableView!
    
    var contactsStore =  CNContactStore()
    var contacts = [ContactStruct]()
    var newContacts = [ContactStruct]()
    let contact = CNMutableContact()
    
    
//    var index = 0
    
//    let contactName = ["Apple", "Alphabet", "Amazon"]
//    let share = [24.341, 31.314, 13.323]
    
//    func onUserAction(data: String){
//        print("Data received: \(data)")
//    }
    
    @IBAction func editContacts(_ sender: UIBarButtonItem) {

        contactTableView.isEditing = !contactTableView.isEditing
        if contactTableView.isEditing{
            editButton.title = "Done"
            
        }else{
            editButton.title = "Edit"
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        contacts.removeAll()
        contactTableView.reloadData()
        self.viewDidLoad()
        editButton.title = "Edit"
        contactTableView.delegate = self
        contactTableView.dataSource = self
        
        contactsStore.requestAccess(for: .contacts) { (success, error) in
            if success {
                print("Authorization Successful")
            }
        }
        
        fetchContacts()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //This will delete ALL USER DEFAULTS ....
//        let domain = Bundle.main.bundleIdentifier!
//        UserDefaults.standard.removePersistentDomain(forName: domain)
//        UserDefaults.standard.synchronize()
//        //print(Array(UserDefaults.standard.dictionaryRepresentation().keys).count)
        //......... take note DON'T UNCOMMENT UNLESS YOU KNOW
        

    }

    func fetchContacts(){
        let key = [CNContactGivenNameKey, CNContactFamilyNameKey, CNContactPhoneNumbersKey, CNContactJobTitleKey]
            as [CNKeyDescriptor]
        let request  = CNContactFetchRequest(keysToFetch: key)
        
        orderItems = UserDefaults.standard.stringArray(forKey: "orderItems") ?? [String]()
        deletedNumbers = UserDefaults.standard.stringArray(forKey: "deletedInfo") ?? [String]()
        
        print(orderItems)
        print(deletedNumbers)
        //-> just use don't save
        
        var index = 0
        if(orderItems.count == 0){
                    try! contactsStore.enumerateContacts(with: request){ (contact, stoppingPointer) in
                        let name = contact.givenName
                        let familyname = contact.familyName
                        let number = contact.phoneNumbers.first?.value.stringValue
            
                        if contact.jobTitle == "CHD Caregiver"{
                            let contactToAppend = ContactStruct(name: name, familyName: familyname, number: number!)
                            var running = true
                            var exist = false
                            var index = 0
            
                            while(running && index < deletedNumbers.count){
                                if(deletedNumbers[index] == contactToAppend.number){
                                    exist = true
                                    running = false;
                                }else{
                                    index = index + 1
                                }
                            }
            
                            if(exist != true) {
                                self.contacts.append(contactToAppend)
                            }
                        }
                    }
        }else{
            while(index < orderItems.count){
                
                try! contactsStore.enumerateContacts(with: request){ (contact, stoppingPointer) in
                    let name = contact.givenName
                    let familyname = contact.familyName
                    let number = contact.phoneNumbers.first?.value.stringValue
                    
                    if contact.jobTitle == "CHD Caregiver" && orderItems[index] == contact.givenName{
                        let contactToAppend = ContactStruct(name: name, familyName: familyname, number: number!)
                        var running = true
                        var exist = false
                        var index = 0
                        
                        deletedNumbers = UserDefaults.standard.stringArray(forKey: "deletedInfo") ?? [String]()
                        
                        while(running && index < deletedNumbers.count){
                            if(deletedNumbers[index] == contactToAppend.number){
                                exist = true
                                running = false;
                            }else{
                                index = index + 1
                            }
                        }
                        
                        if(exist != true) {
                            self.contacts.append(contactToAppend)
                        }
                    }
                }
                index = index + 1
            }
        }
        


        

        contactTableView.reloadData()
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return contacts.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell(style: .subtitle, reuseIdentifier: nil)
        let contactToDisplay = contacts[indexPath.row]
        cell.textLabel?.text = contactToDisplay.name + " " + contactToDisplay.familyName
        cell.detailTextLabel?.text = contactToDisplay.number
        return cell
    }
    
    func tableView(_ tableView: UITableView, canMoveRowAt indexPath: IndexPath) -> Bool {
        return true
    }
    
    func tableView(_ tableView: UITableView, moveRowAt sourceIndexPath: IndexPath, to destinationIndexPath: IndexPath) {
        print("\nThis is the row source: \(sourceIndexPath.row)" )
        print("This is the row destination: \(destinationIndexPath.row)" )
        let selectedItem = contacts[sourceIndexPath.row]
        print("\nThis is the item we are moving -> from contacts: \(selectedItem.name)" )
        
        contacts.remove(at: sourceIndexPath.row)
        contacts.insert(selectedItem, at: destinationIndexPath.row)
    
        orderItems  = [String]()
        var index = 0;
        while(index < contacts.count){
            orderItems.append(contacts[index].name)
            index = index + 1
        }
        UserDefaults.standard.set(orderItems, forKey: "orderItems")
//        UserDefaults.standard.set(self.contacts, forKey: "rearrangedContacts") -> could not save data ->
        //need to find a way to save this array of data type contactStruc
    }
    
    
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete{
            print(indexPath.row)
            print(contacts[indexPath.row].number)
            
            deletedNumbers.append(contacts[indexPath.row].number)
            UserDefaults.standard.set(deletedNumbers, forKey: "deletedInfo")
            deletedNumbers = UserDefaults.standard.stringArray(forKey: "deletedInfo") ?? [String]()
            print(deletedNumbers.count)
            contacts.remove(at: indexPath.row)
            print("This is the number of contacts.count: \(contacts.count)" )
            
            var index = 0;
            orderItems = [String]()
            while(index < contacts.count){
                orderItems.append(contacts[index].name)
                index = index + 1
            }
            UserDefaults.standard.set(orderItems, forKey: "orderItems")
            
            contactTableView.beginUpdates()
            contactTableView.deleteRows(at: [indexPath], with: .automatic)
            contactTableView.endUpdates()
        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func didUnwindFromContactInfoVC(_ sender: UIStoryboardSegue){
        guard let contactInfoVC = sender.source as? EnterContactInfoViewController else {return}
        let name = contactInfoVC.firstNameTextField.text
        let familyname = contactInfoVC.secondNameTextField.text
        let number = contactInfoVC.thirdNumberTextField.text
        
        //First let search if the Contacts exists
        var doesItExistInContacts = false;
        let key = [CNContactGivenNameKey, CNContactFamilyNameKey, CNContactPhoneNumbersKey, CNContactJobTitleKey]
            as [CNKeyDescriptor]
        let request  = CNContactFetchRequest(keysToFetch: key)
        
        orderItems = UserDefaults.standard.stringArray(forKey: "orderItems") ?? [String]()
        
        try! contactsStore.enumerateContacts(with: request){ (contact, stoppingPointer) in
            if(contact.givenName == name && contact.familyName == familyname && contact.phoneNumbers.first?.value.stringValue == number
                && contact.jobTitle == "CHD Caregiver"){
                print("IT in Contacts: check")
                doesItExistInContacts = true;
            }
        }
        
        
        if(doesItExistInContacts){
            deletedNumbers = UserDefaults.standard.stringArray(forKey: "deletedInfo") ?? [String]()
            var index = 0;

            while(index < deletedNumbers.count){
                if(deletedNumbers[index] == number){
                    print("It's in deletedNumber")
                    deletedNumbers.remove(at: index)
                    orderItems.append(name!)
                }
                index = index + 1
            }
            
            UserDefaults.standard.set(deletedNumbers, forKey: "deletedInfo")
            UserDefaults.standard.set(orderItems, forKey: "orderItems")
        }
        
        
        if( doesItExistInContacts == false){
            let contactToAppend = ContactStruct(name: name!, familyName: familyname!, number: number!)
            print(contactToAppend.name)
            newContacts.append(contactToAppend)
            
            if newContacts.count > 0{
                contact.givenName = newContacts[0].name
                contact.familyName = newContacts[0].familyName
                contact.phoneNumbers = [CNLabeledValue(label: CNLabelPhoneNumberMobile, value: CNPhoneNumber(stringValue: newContacts[0].number))]
                contact.jobTitle = "CHD Caregiver"
                let saveContact = CNSaveRequest()
                saveContact.add(contact, toContainerWithIdentifier: nil)
                
                orderItems.append(newContacts[0].name)
                UserDefaults.standard.set(orderItems, forKey: "orderItems")
                try! contactsStore.execute(saveContact)
                print("This is the newContacts.cout: " + "\(newContacts.count)" )
            }
        }
        
        contacts.removeAll()
        contactTableView.reloadData()
        self.viewDidLoad()
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
